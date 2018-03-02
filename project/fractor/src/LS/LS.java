package LS;

import javax.swing.*;
import java.awt.*;
import java.util.*;

public class LS extends JFrame{
    JPanel pan;
    public LS(){
       pan=new MyPannel();
       this.add(pan);
       this.setVisible(true);
       this.setSize(1920,1080);
       this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] argc){
        new LS();
    }
}
class MyPannel extends JPanel{
    String s;
    Integer depth;
    Set<Character> alpha=new HashSet<>();
    Map<Character,String> construct=new HashMap<>();

    public void paint(Graphics g){

    }
}
