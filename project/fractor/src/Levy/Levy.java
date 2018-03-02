package Levy;

import javax.swing.*;
import java.awt.*;

public class Levy extends JFrame{
    JPanel pan;
    public Levy(){
        pan=new MyPannel();
        this.add(pan);
        this.setVisible(true);
        this.setSize(1920,1080);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] argc){
        new Levy();
    }
}

class MyPannel extends JPanel{
    int depth=10;
    public void paint(Graphics g){
        point a=new point(600,300),b=new point(1300,300);
        line l=new line();
        l.set(a,b);
        draw(g,l,0);

    }
    private void draw(Graphics g,line l,int dep){
        /*
        g.drawLine((int)l.a.x,(int)l.a.y,(int)l.b.x,(int)l.b.y);
        if(dep==depth)  return ;
        */
        if(dep==depth){
            g.drawLine((int)l.a.x,(int)l.a.y,(int)l.b.x,(int)l.b.y);
            return;
        }
        line l1=new line(),l2=new line();
        l1.set(l.a,l.c);
        l2.set(l.c,l.b);
        draw(g,l1,dep+1);
        draw(g,l2,dep+1);
    }
}

class line{
    point a,b,c;
    public void set(point p,point q){
        a=p;    b=q;
        c=new point(1,1);
        c.x=(a.x+a.y+b.x-b.y)/2;
        c.y=(b.x+b.y+a.y-a.x)/2;
    }
}

class point{
    double x,y;
    public point(double a,double b){
        this.x=a;
        this.y=b;
    }
}