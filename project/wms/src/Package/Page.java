package Package;

import javax.swing.*;
import java.sql.ResultSet;

public class Page {
    public JFrame frame=null;

    Page(String windowname){
        frame=new JFrame(windowname);
    }
    Page(){}

    Type.NextPage PageMainFun(ResultSet in, StringBuffer out){
        return Type.NextPage.UserHomePage;
    }
}


class LoginPage extends Page{
    private JTable table=null;
    private JPanel panel=null;
    private JComboBox comboBox=null;

    /*
        function:
            Show QueryResult[in] on this page;
            Create SqlStatement[out] by monitor window's events
        paramer:
            in: show [in] in the second call round
            out: create [in] in the first call round
        return value:
            Tell Main which page will show next
            if [in]==null,it mean it's the first call of PageMainFun,
            need to ConstructSql in this call round and NextPage should be the SamePage;
            else need to show [in] in this call round and NexPage Shoule be
            UserHomePage[AdministratorHomePage/BossHomePage]
     */
    Type.NextPage PageMainFun(ResultSet in,StringBuffer out){
        out.setLength(0);
        if(in==null){

            return Type.NextPage.LoginPage;
        }
        else{

        }
        return Type.NextPage.UserHomePage;
    }
}

class EditPage extends Page{
    private JTable table=null;
    private JPanel panel=null;
    private JComboBox comboBox=null;

    Type.NextPage PageMainFun(ResultSet in,StringBuffer out){
        out.setLength(0);
        if(in==null){

            return Type.NextPage.EditPage;
        }
        else{

        }
        return Type.NextPage.UserHomePage;
    }
}

class ViewPage extends Page{
    private JTable table=null;
    private JPanel panel=null;
    private JComboBox comboBox=null;

    Type.NextPage PageMainFun(ResultSet in,StringBuffer out){
        out.setLength(0);
        if(in==null){

            return Type.NextPage.ViewPage;
        }
        else{

        }
        return Type.NextPage.UserHomePage;
    }
}

//UserHomePage

class AdministratorHomePage extends Page{
    private JTable table=null;
    private JPanel panel=null;
    private JComboBox comboBox=null;

    /*
        function:
            monitor events and determine NextPage
        paramer:
            in: useless
            out: useless
        return value:
            Tell Main which page will show next
     */
    Type.NextPage PageMainFun(ResultSet in,StringBuffer out){
        Type.NextPage nextpage=Type.NextPage.EditPage;

        return nextpage;
    }
}
class BossHomePage extends Page{
    private JTable table=null;
    private JPanel panel=null;
    private JComboBox comboBox=null;

    Type.NextPage PageMainFun(ResultSet in,StringBuffer out){
        out.setLength(0);
        Type.NextPage nextpage=Type.NextPage.EditPage;

        return nextpage;
    }
}