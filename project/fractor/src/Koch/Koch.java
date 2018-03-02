package Koch;

import javax.swing.*;
import java.awt.*;

public class Koch extends JFrame {
    public static void main(String[] argc){
        new Koch();
    }
    public Koch(){
        JPanel jp=new MyPannel();
        this.add(jp);
        this.setSize(1920,1080);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
class MyPannel extends JPanel{
    int Max=5;
    void draw(double ax,double ay,double ex,double ey,Graphics g,int times){
        double bx,by,cx,cy,dx,dy;
        double deg,len;
        if(times>Max){
            g.drawLine((int)ax,(int)ay,(int)ex,(int)ey);
            return;
        }
        len=Math.hypot(ex-ax,ey-ay)/3;
        deg=rough(Math.atan((ey-ay)/(ex-ax)));
        if(deg>=0&&ex-ax<0||deg<=0&&ex-ax<0)    deg=deg+Math.PI;
        bx=ax+(ex-ax)/3;by=ay+(ey-ay)/3;
        dx=ex-(ex-ax)/3;dy=ey-(ey-ay)/3;
        cx=bx+len*Math.cos(deg);cy=by+len*Math.sin(deg);
        draw(ax,ay,bx,by,g,times+1);
        draw(bx,by,cx,cy,g,times+1);
        draw(cx,cy,dx,dy,g,times+1);
        draw(dx,dy,ex,ey,g,times+1);
    }
    double rough(double x){
        x=x/Math.PI*180;
        while(x<0)  x=x+360;
        int k=(int)x/60;
        if(k*60-(int)x>=0) x=k*60+60;
        else x=(k+1)*60+60;
        x=x/180*Math.PI;
        return x;
    }
    public void paint(Graphics g){
        super.paint(g);
        g.setColor(Color.black);
        draw(560,800,1360,800,g,0);
        //draw(960,108,560,800,g,0);
        //draw(1360,800,960,108,g,0);
    }
}
