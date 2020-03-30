import java.io.*;
import java.util.*;

/**
 * CCC07S4
 */
public class CCC07S4 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] poss = new int[N+1];
        poss[1] = 1;
        ArrayList<Integer>[] adj = new ArrayList[N+1];
        for(int i = 0; i<N+1; i++){
            adj[i] = new ArrayList<>();
        }
        while(true){
            String temp = br.readLine();
            if(temp.equals("0 0")){
                break;
            }
            int src = Integer.parseInt(temp.split(" ")[0]);
            int dest = Integer.parseInt(temp.split(" ")[1]);
            adj[dest].add(src);
        }

        for(int i = 2; i<N+1; i++){
            for(int k: adj[i]){
                poss[i]+=poss[k];
            }
        }

        System.out.println(poss[N]);


    }
}