import java.io.*;
import java.util.*;
public class FileIO {
    void solve()throws Exception{
        File f=new File("./abc.in");
        Scanner scan=new Scanner(f);
        int k;
        k=scan.nextInt();
        System.out.println(k);
    }
    public static void main(String[] argc){
        try{
            new FileIO().solve();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}