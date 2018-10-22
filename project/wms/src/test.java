import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Vector;

import javax.swing.AbstractListModel;
import javax.swing.Action;
import javax.swing.BorderFactory;
import javax.swing.ComboBoxModel;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;

//=================================================
// File Name       :    MyComboBox_demo
//------------------------------------------------------------------------------
// Author          :    Common



//类名：MyComboBox
//属性：
//方法：

class MyComboBox implements ItemListener,ActionListener{
    private JFrame frame = new JFrame("窗体");                    //定义窗体
    private Container cont = frame.getContentPane();            //得到窗体容器
    private JComboBox jcb1  = null;                                         //定义下拉列表框
    private JLabel label  = new JLabel("标签");                           //定义标签
    private String fontSize[] = {"10","11","12"};

    public MyComboBox(){
        this.frame.setLayout(new GridLayout(2,2));

        this.jcb1 = new JComboBox(this.fontSize);       //实例化JComboBox
        //定义一个列表框的边框显示条
        jcb1.setBorder(BorderFactory.createTitledBorder("请选择显示文字大小"));

        jcb1.addItemListener(this);                     //加入选项监听
        jcb1.addActionListener(this);               //加入动作监听

        jcb1.setMaximumRowCount(3);             //最多显示3个选项
        jcb1.setEditable(true);                             //设置可编辑文本
        jcb1.configureEditor(jcb1.getEditor(), "12");       //定义默认值
        this.changeFontSize(12);                        //设置默认字体

        cont.add(this.jcb1);
        cont.add(label);

        cont.add(new JLabel("下拉列表框"));
        this.frame.setSize(330,200);
        this.frame.setVisible(true);
        this.frame.addWindowListener(new WindowAdapter(){   //加入事件监听
            public void windowClosing(WindowEvent arg0) {           //窗口关闭时触发，按下关闭按钮
                // TODO 自动生成的方法存根
                System.out.println("windowClosing-->窗口关闭");
                System.exit(1);
            }
        });
    }
    @Override
    public void actionPerformed(ActionEvent e) {        //输入信息时触发
        // TODO 自动生成的方法存根
        String itemSize = (String) this.jcb1.getSelectedItem(); //得到选项
        int Size = 12;
        try{
            Size = Integer.parseInt(itemSize);      //字符串转整数
        }catch(Exception ex){
            this.jcb1.getEditor().setItem("输入的不是数字");
        }
        this.changeFontSize(Size);
        if(!this.isExists(itemSize)){
            this.jcb1.addItem(jcb1.getSelectedItem());      //不存在，加入下拉选项
        }
    }
    @Override
    public void itemStateChanged(ItemEvent e) {
        // TODO 自动生成的方法存根

    }

    public void changeFontSize(int size){           //改变文字大小
        Font font = new Font("Serief",Font.BOLD,size);      //定义Font对象
        this.label.setFont(font);                                                   //设置文字大小
    }

    public boolean isExists(String item){
        boolean flag = false;
        for(int i =0;i<this.jcb1.getItemCount();i++){
            if(item.equals(this.jcb1.getItemAt(i))){
                flag = true;
            }
        }
        return flag;
    }

}



//主类
//Function        :     MyComboBox_demo
public class test {

    public static void main(String[] args) {
        // TODO 自动生成的方法存根
        //new MyComboBox();
        StringBuffer a=new StringBuffer();
        a.append("dasdwq");
        fun(a);
        System.out.println(a);
    }
    static void fun(StringBuffer a) {
        a=new StringBuffer();
        //a.setLength(0);
        a.append("sdasd");
    }
}
