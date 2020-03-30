import java.io.*;
import java.util.*;

/**
 * CCC02S4 - Bridge Crossing
 */

public class CCC02S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        int Q = Integer.parseInt(br.readLine());
        String[] names = new String[Q];
        int[] prev = new int[Q];
        int[] times = new int[Q];
        int[] shortestTime = new int[Q];
        for(int i = 0; i<Q; i++){
            names[i] = br.readLine();
            times[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 0; i<Q; i++){
            int max = 0;
            for(int m = 0;m<M && i+m<Q; m++){
                int newIndex = i+m;
                max = Math.max(max,times[newIndex]);
                if(i>=1){
                    if(shortestTime[newIndex] == 0 || shortestTime[newIndex]>=shortestTime[i-1] + max){
                        shortestTime[newIndex] = shortestTime[i-1]+max;
                        prev[newIndex] = i-1;
                    }
                }
                else{
                    shortestTime[newIndex] = max;
                    prev[newIndex] = -1;
                }
                
            }
        }


        Stack<Integer> order = new Stack<>();

        int finalIndex = Q-1;
        System.out.println("Total Time: " + Integer.toString(shortestTime[finalIndex]));
        order.push(Q);
        while(!(finalIndex == -1)){
            order.push(prev[finalIndex]+1);
            finalIndex = prev[finalIndex];
        }

        int currPrint = 0;
        
    
        while(!order.isEmpty()){
            int next = order.pop();
            //System.out.println(next);
            if(next != 0){
                for(int i = currPrint;i<next;i++){
                    System.out.print(names[i] + " ");
                }
                currPrint = next;
                System.out.println();
            }
            
        }


    }
}