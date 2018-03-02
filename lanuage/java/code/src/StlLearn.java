import java.util.*;

public class StlLearn {
    public static void main(String[] argc){
        StlLearn a=new StlLearn();
        a.map();
        a.set();
        a.linklist();
        a.queue();
        a.stack();
    }
    void map(){
        System.out.println("map:");
        Map<Integer,Integer> m1=new HashMap<>();
        Map<Integer,Integer> m2=new TreeMap<>();
        //...more
        m1.put(10,1000);
        m1.put(60,1);
        System.out.println(m1.get(10));
        System.out.println(m1);
        System.out.println();
    }
    void set(){
        System.out.println("Set:");
        Set<Integer> s1=new HashSet<>();
        Set<Integer> s2=new TreeSet<>();
        //...more
        s1.add(1);s1.add(2);s1.add(1);
        System.out.println(s1);
        System.out.println();
    }
    void linklist(){
        System.out.println("LinkedList:");
        LinkedList<Integer> lin1=new LinkedList<>(),lin2=new LinkedList<>();
        int i;
        for(i=0;i<10;i++)lin1.add(i);
        for(;i<20;i++)lin2.add(i);
        ListIterator<Integer>p1=lin1.listIterator(),p2=lin2.listIterator();
        while(p1.hasNext()){
           if(p1.next().equals(5))break;
        }
        p1.remove();
        while(p2.hasNext()){
            p1.add(p2.next());
        }
        System.out.println(lin1);
        System.out.println();
    }
    void queue(){

    }
    void stack(){
        System.out.println("Stack:");

    }
}