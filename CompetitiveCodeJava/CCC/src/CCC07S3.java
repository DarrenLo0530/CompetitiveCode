import java.io.*;
import java.util.*;

/**
 * CCCS3J7 - Friends
 */
public class CCC07S3 {
    public static void findFriend(int next, int target, int counter, Map<Integer, Integer[]> assign){
        assign.get(next)[0] = 1;
        int after = assign.get(next)[1];
        if(after == target){
            System.out.println("Yes " + Integer.toString(counter));
            return;
        }
        else if(assign.get(after)[0] == 1){
            System.out.println("No");
            return;
        }
        else{
            counter+=1;
            findFriend(after,target,counter,assign);
        }
        
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Map<Integer,Integer[]> assign = new HashMap<>();

        for(int i = 0;i<n;i++){
            String[] x = br.readLine().split(" ");
            int in = Integer.parseInt(x[0]);
            int out = Integer.parseInt(x[1]);
            Integer[] temp = {0,out};
            assign.put(in,temp);
        }
        boolean done = false;
        while(!done){
            String[] input = br.readLine().split(" ");
            if(input[0].equals("0") && input[1].equals("0")){
                done = true;
            }
            else{
                for(int e: assign.keySet()){
                    assign.get(e)[0] = 0;
                }
                int person = Integer.parseInt(input[0]);
                int friend = Integer.parseInt(input[1]);
                findFriend(person,friend,0,assign);
            }
        }
    }
}