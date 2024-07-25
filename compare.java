import java.util.*;
public class compare {
    public static void main(String args[]){
        //compare
        String name1="shivani";
        String name2="kurmi";

        //s1>s2 to +value
        //s1=s2 to 0
        //s1<s2 to -value

        if(name1.compareTo(name2)==0){
            System.out.println("Strings are equal");

        }else{
            System.out.println("Strings are not equal");
        }
    }
    
}
