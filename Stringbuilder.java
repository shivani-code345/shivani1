import java.util.*;
public class Stringbuilder {
    public static void main(String args[]){
        StringBuilder sb = new StringBuilder("shivani");
        System.out.println(sb);

        //char index at 0
        //System.out.println(sb.charAt(0));

        //set char at index
       // sb.setCharAt(0,'k');
       // System.out.println(sb);

       //insert function use 
      // sb.insert(0,'s');
       //System.out.println(sb);
       //how to delete
       sb.delete(0,3);
       System.out.println(sb);

    }
    
}
