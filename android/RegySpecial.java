import javax.swing.*;
import java.awt.*;
class RegySpecial{
  public static void main(String[] args){
    try{
      JFrame frame = new JFrame("RegySpecial"){
        public void paint(Graphics g){
          g.drawImage(new ImageIcon("../blobs/images/author-4745750_1280.jpg").getImage(),0,0,(int)Toolkit.getDefaultToolkit().getScreenSize().getWidth(),(int)Toolkit.getDefaultToolkit().getScreenSize().getHeight(),null);
        }
      };
      JTextField textField = new JTextField("User");
      final String[][] buttonTextGrid={{"Play","Exit"},{"Options","Credits"}};
      frame.setIconImage(new ImageIcon("../../../RegySpecial.jpg").getImage().getScaledInstance(100, 100, 1));
      frame.setUndecorated(true);
      frame.setResizable(true);
      frame.setBounds(
				0,
				0,
				(int)Toolkit.getDefaultToolkit().getScreenSize().getWidth(),
				(int)Toolkit.getDefaultToolkit().getScreenSize().getHeight()
			);
      frame.setVisible(true);
      frame.setLayout(null);
      textField.setBounds(
				(int)(Toolkit.getDefaultToolkit().getScreenSize().getWidth()/4),
				(int)(Toolkit.getDefaultToolkit().getScreenSize().getHeight()/4),
				(int)(Toolkit.getDefaultToolkit().getScreenSize().getWidth()/2),
				100
			);
      textField.setBackground(new Color(0,128,255));
      textField.setForeground(Color.yellow);
      frame.add(textField);
      JPanel buttonGrid=new JPanel();
			buttonGrid.setBounds(
				0,
				(int)(Toolkit.getDefaultToolkit().getScreenSize().getWidth()/2),
				(int)(Toolkit.getDefaultToolkit().getScreenSize().getWidth()),
				(int)(Toolkit.getDefaultToolkit().getScreenSize().getHeight()/2)
			);
      GridLayout gridLayout=new GridLayout(2,2,10,10);
      buttonGrid.setLayout(gridLayout);
      for(final String[] buttonRow:buttonTextGrid){
        for(final String text:buttonRow){
          JButton button=new JButton(text);
					buttonGrid.add(button);
        }
      }
			frame.add(buttonGrid);
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
