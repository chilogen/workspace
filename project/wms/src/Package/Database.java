package Package;

import java.sql.*;
import java.util.Vector;

public class Database {
    Connection sqlcontion;
    Statement sqlstatment;
    ResultSet queryresult;

    private void conntect(String drivername,String url,String Username,String Passwd){
        try {
            Class.forName(drivername);
            sqlcontion=DriverManager.getConnection(url,Username,Passwd);
        }
        catch (ClassNotFoundException e){
            System.out.println(e);
        }
        catch (SQLException e){
            System.out.println(e);
        }
    }

    private boolean SytaxCheck(){
        return true;
    }

    void DatabaseFun(){

    }

    StringBuffer ConstructSql(Type.Command cmd){
        StringBuffer ans=new StringBuffer();
        switch (cmd){
            case Update:{
                //do someting
            }
        }
        return ans;
    }

}
