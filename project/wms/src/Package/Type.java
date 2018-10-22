package Package;

public class Type {
    public enum View{
        BossAuthView,
        ChefReportDamageView,
        ChefReportLostView;
    }
    public enum Table{
        MainTable;
    }
    public enum User{
        Boss,
        Chef;
    }
    public enum NextPage{
        UserHomePage,
        LoginPage,
        EditPage,
        ViewPage;
    }
    public enum Command{
        Insert,
        Delete,
        Update,
        Select,
        Create,
        None;
    }
}
