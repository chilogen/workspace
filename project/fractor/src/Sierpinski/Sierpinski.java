package Sierpinski;

import javax.swing.*;
import java.awt.*;

public class Sierpinski extends JFrame {
    JPanel pan;
    public Sierpinski(){
        pan=new MyPannel();
        this.add(pan);
        this.setSize(1920,1080);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] argc){
        new Sierpinski();
    }
}

class MyPannel extends JPanel{
    INT x=new INT(),y=new INT();
    int depth=4;
    public void paint(Graphics g){
        SetTraingle();;
        draw(g,x,y,0,true);
    }
    void SetTraingle(){
        x.set(100,1800,950);
        y.set(900,900,100);
    }
    void draw(Graphics g,INT a,INT b,int dep,boolean drawable){
        Polygon p=new Polygon(a.decompos(),b.decompos(),3);
        g.drawPolygon(p);
        if(dep==depth){
            if(drawable){
                g.setColor(Color.GRAY);
                g.fillPolygon(p);
            }
            return;
        }
        int[] x=a.decompos(),y=b.decompos();
        INT c=new INT((x[0]+x[1])/2,(x[0]+x[2])/2,(x[1]+x[2])/2);
        INT d=new INT((y[0]+y[1])/2,(y[0]+y[2])/2,(y[1]+y[2])/2);
        //draw(g,c,d,dep+1,true);
        draw(g,new INT(a.get(0),c.get(0),c.get(1)),new INT(b.get(0),d.get(0),d.get(1)),dep+1,true);
        draw(g,new INT(a.get(1),c.get(0),c.get(2)),new INT(b.get(1),d.get(0),d.get(2)),dep+1,true);
        draw(g,new INT(a.get(2),c.get(1),c.get(2)),new INT(b.get(2),d.get(1),d.get(2)),dep+1,true);
    }
}

class INT{
    int x[]=new int[3];
    public INT(int a,int b,int c){
        this.x[0]=a;
        this.x[1]=b;
        this.x[2]=c;
    }
    public INT(){}
    public void set(int a,int b,int c){
        this.x[0]=a;
        this.x[1]=b;
        this.x[2]=c;
    }
    public int get(int a){
        return x[a];
    }
    public int[] decompos(){
        return x;
    }
}