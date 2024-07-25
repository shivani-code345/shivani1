import java.util.*;
import java.util.LinkedList;

public class hashing {
    static class HashMap<k,v>{
        private class Node{
            k key;
            v value;

            public Node(k key, v value){
                this.key = key;
                this value = value;

            }

        }
        private int n;
        private int N;
        private LinkedList<Node> buckets[];

        @SuppressWarnings ("unchecked")
        public HashMap(){
            this.N=4;
           this.buckets=new LinkedList[4];
           for(int i=0; i<4; i++){
            this.buckets[]=new LinkedList<>();
           }
        }
        public hashFunction(){


        }

    }
}
