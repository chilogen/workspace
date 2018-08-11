import java.io.*; 
import java.util.*; 
import java.math.BigDecimal;

public class Main { 
    public static void main(String[] args) throws Exception {  
        Scanner cin = new Scanner(System.in); 
        String x1=cin.nextLine();
        String x2=cin.nextLine();
        String x3=cin.nextLine();
        BigDecimal a1=new BigDecimal(x1);
        BigDecimal a2=new BigDecimal(x2);
        BigDecimal a3=new BigDecimal(x3);
        BigDecimal ans1=null;
        BigDecimal ans2=null;
        BigDecimal ans3=null;
        BigDecimal ans4=null;
        BigDecimal ans5=null;
        BigDecimal ans6=null;
        ans1=a1.add(a1);
        ans2=a1.add(a2);
        ans3=a1.add(a3);
        ans4=a2.add(a2);
        ans5=a2.add(a3);
        ans6=a3.add(a3);
        if(ans1.compareTo(a1)==0||ans1.compareTo(a2)==0||ans1.compareTo(a3)==0||ans2.compareTo(a1)==0||ans2.compareTo(a2)==0||ans2.compareTo(a3)==0||ans3.compareTo(a1)==0||ans3.compareTo(a2)==0||ans3.compareTo(a3)==0||ans4.compareTo(a1)==0||ans4.compareTo(a2)==0||ans4.compareTo(a3)==0||ans5.compareTo(a1)==0||ans5.compareTo(a2)==0||ans5.compareTo(a3)==0||ans6.compareTo(a1)==0||ans6.compareTo(a2)==0||ans6.compareTo(a3)==0)
        {
        	System.out.println("YES");
        }
        else System.out.println("NO");
    }  
}