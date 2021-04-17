import java.util.*;
public class l001{
    public static Scanner scn = new Scanner(System.in);
    
    public static int boardPath_opti(int tar) {
        LinkedList<Integer> list = new LinkedList<>();
        for(int i=0;i<=tar;i++){
            if(i<=1){
                list.addFirst(1);
            }else{
                if(list.size()<=6) list.addFirst(list.getFirst()*2);
                else list.addFirst(list.getFirst()*2 - list.removeLast());
            }
        }
        return list.getFirst();
    }

    public static int boardPath_opti(int tar,int[] arr) {
        int n = arr.length;
        for(int i=0;i<=tar;i++){
            if(i<=1){
                arr[i]=1;
            }
            else{
                if(i<=6){
                    arr[i] = arr[i-1]*2;
                }else{
                    int idx = i%n;
                    int preidx = (i-1) % n;
                    arr[idx] = arr[preidx]*2 - arr[idx]; 
                }
            }
        }
        return arr[tar%n];
    }




    public static void main(String[] args){
       System.out.println(boardPath_opti(20)); // LL
       int[] pre =  new int[7];
       System.out.println(boardPath_opti(20,pre));

    }
}