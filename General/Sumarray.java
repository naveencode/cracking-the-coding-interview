import java.util.*;
import java.io.*;
public class Sumarray{
    public static void main(String a[]){
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int l=in.nextInt();
            int target=in.nextInt();
            int[] arr=new int[l];
            for(int j=0;j<l;j++){
                arr[i]=in.nextInt();
            }
            if(!rec(arr,0,0,0,target))
                System.out.println(-1);
        }
    }
    public static boolean rec(int[] arr,int sum,int start,int curr,int target){
        if(sum==target){
            System.out.println(start+" "+(curr-1));
            return true;
        }
        if(sum>target)
             return false;
        if(curr==arr.length)
            return false;
       return rec(arr,sum+arr[curr],start,curr+1,target)||rec(arr,arr[curr],curr,curr+1,target);
    }
}