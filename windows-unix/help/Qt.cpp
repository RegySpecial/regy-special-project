/*By Leo AI*/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <vector>
#include <string>

// Forward declaration for the Application class
class Application;

// --- Base Widget Class (Mimics QWidget) ---
class Widget {
protected:
    Window x11_window;
    Display* display;
    int x, y, width, height;
    bool visible;
    Widget* parent;

public:
    Widget(Display* d, Widget* p = nullptr, int w = 100, int h = 100) 
        : display(d), parent(p), x(100), y(100), width(w), height(h), visible(false) {
        
        // Create the raw X11 window
        // Root window is the screen
        Window root = DefaultRootWindow(display);
        
        x11_window = XCreateSimpleWindow(display, root, x, y, width, height, 1, 0, 0);
        
        // Set window properties (Title, Close button handling)
        XStoreName(display, x11_window, "Qt-like C++ Window");
        
        // Select events we care about (Exposure, Resize, Mouse, Close)
        long event_mask = ExposureMask | StructureNotifyMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask;
        XSelectInput(display, x11_window, event_mask);
        
        // Tell the window manager we want to handle the close button
        Atom wm_delete = XInternAtom(display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(display, x11_window, &wm_delete, 1);
    }

    virtual ~Widget() {
        if (x11_window) {
            XDestroyWindow(display, x11_window);
        }
    }

    // --- Virtual Event Handlers (The "Logic") ---
    // Override these in your subclass
    virtual void paintEvent() {
        // Default: clear background
        GC gc = XCreateGC(display, x11_window, 0, nullptr);
        XSetForeground(display, gc, 0xffffff);
        XFillRectangle(display, x11_window, gc, 0, 0, width, height);
        XFreeGC(display, gc);
    }

    virtual void resizeEvent(int w, int h) {
        width = w;
        height = h;
        std::cout << "Resized to: " << width << "x" << height << std::endl;
    }

    virtual void mousePressEvent(int x, int y, int button) {
        std::cout << "Mouse Press at (" << x << ", " << y << ") Button: " << button << std::endl;
    }

    // --- Public API ---
    void show() {
        if (!visible) {
            XMapWindow(display, x11_window);
            visible = true;
        }
    }

    void hide() {
        if (visible) {
            XUnmapWindow(display, x11_window);
            visible = false;
        }
    }

    void update() {
        if (visible) {
            // Force a repaint
            paintEvent();
        }
    }

    // Getters for geometry management
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    Window getX11Window() const { return x11_window; }
};

// --- Custom Widget Example (Mimics a specific Qt Widget) ---
class MyLabel : public Widget {
private:
    std::string text;

public:
    MyLabel(Display* d, const std::string& t, Widget* parent = nullptr) 
        : Widget(d, parent, 300, 100), text(t) {}

    void paintEvent() override {
        // Clear background
        GC gc = XCreateGC(display, x11_window, 0, nullptr);
        
        // Fill white background
        XSetForeground(display, gc, 0xffffff);
        XFillRectangle(display, x11_window, gc, 0, 0, width, height);
        
        // Draw text (Black)
        XSetForeground(display, gc, 0);
        XSetFont(display, gc, XLoadFont(display, "-*-helvetica-medium-r-*-*-14-*-*-*-*-*-*-*"));
        
        // Draw string centered
        int text_width = XTextWidth(XQueryFont(display, XGContextFromGC(gc)), text.c_str(), text.length());
        int x_pos = (width - text_width) / 2;
        int y_pos = (height + 14) / 2; // Approximate centering
        
        XDrawString(display, x11_window, gc, x_pos, y_pos, text.c_str(), text.length());
        
        // Draw a border
        XSetForeground(display, gc, 0x0000FF); // Blue
        XDrawRectangle(display, x11_window, gc, 0, 0, width-1, height-1);
        
        XFreeGC(display, gc);
    }

    void mousePressEvent(int x, int y, int button) override {
        std::cout << "Clicked Label: '" << text << "' at (" << x << ", " << y << ")" << std::endl;
        // Simulate a color change on click
        update(); 
    }
};

// --- Application Class (Mimics QApplication) ---
class Application {

public:
    Display* display;
    std::vector<Widget*> widgets;
    bool running;
    Application() : running(true) {
        display = XOpenDisplay(nullptr);
        if (!display) {
            throw std::runtime_error("Cannot open X11 display");
        }
    }

    ~Application() {
        if (display) XCloseDisplay(display);
    }

    void addWidget(Widget* w) {
        widgets.push_back(w);
    }

    int exec() {
        std::cout << "Starting Event Loop..." << std::endl;
        XEvent event;
        
        while (running && running) {
            XNextEvent(display, &event);
            
            // Find which widget owns this event
            Widget* target = nullptr;
            for (auto w : widgets) {
                if (w->getX11Window() == event.xany.window) {
                    target = w;
                    break;
                }
            }

            if (!target) continue;

            switch (event.type) {
                case Expose:
                    // Only repaint if it's the full expose or if we need to
                    target->paintEvent();
                    break;

                case ConfigureNotify:
                    if (event.xconfigure.width != target->getWidth() || 
                        event.xconfigure.height != target->getHeight()) {
                        target->resizeEvent(event.xconfigure.width, event.xconfigure.height);
                    }
                    break;

                case ButtonPress:
                    target->mousePressEvent(event.xbutton.x, event.xbutton.y, event.xbutton.button);
                    break;

                case ClientMessage:
                    // Handle WM_DELETE_WINDOW
                    if ((Atom)event.xclient.data.l == XInternAtom(display, "WM_DELETE_WINDOW", False)) {
                        running = false;
                    }
                    break;
            }
        }
        return 0;
    }
};

// --- Main Entry Point ---
int main() {
    try {
        Application app;
        
        // Create our custom widget
        auto label = new MyLabel(app.display, "Hello, X11 (Qt Style)!", nullptr);
        
        app.addWidget(label);
        label->show();

        return app.exec();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}