package Package;

import java.sql.*;
import java.util.Vector;

public class User {
    int UserID;
    Vector<Database>D;

    User(){
        D.setSize(5);
    }

    public void login(String Username,String Passwd){

    }

    private Database ConnecUserDatabase(){

        return new Database();
    }

    private void ConnectUserDatabase(String Username,String Passwd){

    }

    /*public ResultSet sqlexec(StringBuffer sql){

    }*/
}
