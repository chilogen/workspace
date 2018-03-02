package Arboresent;

import javax.swing.*;
import java.awt.*;

public class Arboresent extends JFrame{
    JPanel pan;
    public Arboresent(){
        pan=new MyPanel();
        this.add(pan);
        this.setSize(1920,1080);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] argc){
        new Arboresent();
    }
}

class MyPanel extends JPanel{
    int depth=5;
    double alpha=10.0/180*Math.PI,len=900,theta=1.0/4*Math.PI;
    point p1=new point(),p2=new point(),p3=new point(),p4=new point(),p5=new point();
    public void paint(Graphics g){
        getcoord(new point(1000,60));
        draw(g,p3,p5,p1,1);
        draw(g,p4,p2,p5,1);
    }
    public void getcoord(point a){
        p5=a;
        p1.set(a.x-len*Math.sin(alpha/2),a.y+len*Math.cos(alpha/2));
        p2.set(a.x+len*Math.sin(alpha/2),a.y+len*Math.cos(alpha/2));
        double l=len/Math.sin(alpha+Math.PI/2)*Math.sin(Math.PI/4-alpha/2);
        p3.set(a.x-len*Math.sin(theta),a.y+l*Math.cos(theta));
        p4.set(a.x+len*Math.sin(theta),a.y+l*Math.cos(theta));

    }
    private void draw(Graphics g,point a,point b,point c,int dep){
        if(dep==depth){
            g.drawLine((int)a.x,(int)a.y,(int)b.x,(int)b.y);
            g.drawLine((int)a.x,(int)a.y,(int)c.x,(int)c.y);
            g.drawLine((int)b.x,(int)b.y,(int)c.x,(int)c.y);
            return;
        }
        double alpha1=Math.PI/2+alpha,alpha2=Math.PI/4-alpha/2,alpha3=Math.PI-alpha1;
        double x,y,z,xx,yy;
        x=Math.hypot((a.x-b.x),(a.y-b.y));
        y=x/Math.sin(alpha1)*Math.sin(alpha2);
        z=y/Math.sin(alpha3)*Math.sin(alpha);
        double alpha4=Math.atan((b.y-c.y)/(b.x-c.x));
        if((alpha4<0&&b.x>c.x&&b.y<c.y)||(alpha4>0&&b.x>c.x&&b.y>c.y))  alpha4=alpha4+Math.PI;
        //the next four lines determin the opening position of the triangle
        point p=new point(b.x+y*Math.cos(alpha4),b.y+y*Math.sin(alpha4));
        point q=new point(p.x+z*Math.cos(alpha4),p.y+z*Math.sin(alpha4));
        draw(g,q,c,a,dep+1);
        draw(g,p,a,b,dep+1);
        /*
        point p=new point(b.x+y*Math.cos(alpha4),b.y+y*Math.sin(alpha4));
        point q=new point(p.x-z*Math.cos(alpha4),p.y-z*Math.sin(alpha4));
        draw(g,p,c,a,dep+1);
        draw(g,q,a,b,dep+1);
         */
    }
}

class point{
    double x,y;
    public point(){}
    public point(double a,double b){
        this.x=a;
        this.y=b;
    }
    public void set(double a,double b){
        this.x=a;
        this.y=b;
    }
}