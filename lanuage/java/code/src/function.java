import java.util.Scanner;

public class function {
    void funa(){
        System.out.println("I am function a!");
    }
    void funb(Object a){

    }
    public static void main(String[] argcv){
        Integer a,b;
        Scanner scan=new Scanner(System.in);
        a=scan.nextInt();
        b=scan.nextInt();
        new function().swap(a,b);
        System.out.println(a);
        System.out.println(b);
    }
    void swap(Integer a,Integer b){
        Integer c=a;
        a=b;
        b=c;
    }
}
