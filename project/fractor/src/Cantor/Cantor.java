package Cantor;

import javax.swing.*;
import java.awt.*;

public class Cantor extends JFrame{
    JPanel pan;
    public static void main(String[] argc) {
        new Cantor();
    }
    public Cantor(){
        pan=new MyPannel();
        this.add(pan);
        this.setSize(1920,1080);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
class MyPannel extends JPanel{
    double Min=1;
    void draw(int x,int y,int len,Graphics g){
        g.drawLine(x,y,x+len,y);
        if(len<Min) return;
        len=len/3;
        draw(x,y+30,len,g);
        draw(x+2*len,y+30,len,g);
    }
    public void paint(Graphics g)
    {
        super.paint(g);
        g.setColor(Color.black);
        draw(0,100,1920,g);
    }
}
