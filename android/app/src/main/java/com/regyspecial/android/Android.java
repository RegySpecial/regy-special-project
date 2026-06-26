package app.src.main.java.com.regyspecial.android;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.*;
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final TextView tvGreetings= (TextView) findViewById(R.id.User);
        Button btnPremi=(Button)findViewById(R.id.btnPremi);
        btnPremi.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                PopupWindow PlayDialog=new PopupWindow();
            }
        });
    }
}