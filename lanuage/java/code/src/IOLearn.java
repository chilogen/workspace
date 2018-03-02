import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;
public class IOLearn
{
    int abc1,abc2;
    Integer Abc;
    IOLearn()
    {
        abc1=10;abc2=15;
        System.out.printf("abc: %2$#x\n",abc1,abc2);
    }
    public void read1()
    {
        BufferedReader buff=new BufferedReader(
                new InputStreamReader(System.in));
        String s;
        try{
            s=buff.readLine();
            System.out.println(s);
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
    public void read2()
    {
        try{
            int k=(int)System.in.read()-(int)'0';
            System.out.println(k);
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
    public void read3()
    {
        Scanner scan=new Scanner(System.in);
        int d;
        float f;
        double lf;
        if(scan.hasNextInt())
        {
            d=scan.nextInt();
            System.out.println(d);
        }
        else if(scan.hasNextFloat())
        {
            f=scan.nextFloat();
            System.out.println(f);
        }
    }
    public static void main(String argc[])
    {
        IOLearn m=new IOLearn();
        System.out.println("read1:");
        m.read1();
        System.out.println("read2:");
        m.read2();
        System.out.println("read3:");
        m.read3();
    }
}