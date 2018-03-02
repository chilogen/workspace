import java.io.*;

public class serializable{
    public static void WriteObjecct()throws Exception{
        plane p=new plane("74644",150.4);
        FileOutputStream f=new FileOutputStream("ObjectFile");
        ObjectOutputStream obj=new ObjectOutputStream(f);
        obj.writeObject(p);
        obj.close();
    }
    public static void ReadObject()throws Exception{
        FileInputStream f=new FileInputStream("ObjectFile");
        ObjectInputStream obj=new ObjectInputStream(f);
        plane p=(plane)obj.readObject();
        System.out.println(p.getFlightNum());
        System.out.println(p.getWeight());
        obj.close();
    }
    public static void main(String[] argc){
        try{
            WriteObjecct();
            ReadObject();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}

class plane implements Serializable{
    private String FlightNum;
    private double Weight;
    public String getFlightNum(){
        return this.FlightNum;
    }
    public double getWeight(){
        return this.Weight;
    }
    public plane(String a,double b){
        this.FlightNum=a;
        this.Weight=b;
    }
}