import java.io.*;
import java.util.*;

/**
 * ANoisyClass
 */
public class ANoisyClass {
    static int N;
    static boolean cycle = false;
    static boolean[] unVisited;
    static boolean[] visiting;
    static boolean[] visited;
    public static void detectCycle(int start, ArrayList<Integer>[] adj){
        unVisited[start] = false;
        visiting[start] = true;
        for(int i:adj[start]){
            if(visiting[i]){
                cycle = true;
            }
            else if(unVisited[i]){
                detectCycle(i,adj);
            }
        }
        visiting[start] = false;
        visited[start] = true;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        unVisited = new boolean[N+1];
        visiting = new boolean[N+1];
        visited = new boolean[N+1];

        ArrayList<Integer>[] adj = new ArrayList[N+1];
        for(int q = 0;q<N+1;q++){
            adj[q] = new ArrayList<>();
        }
        for(int i = 0;i<M;i++){
            String[] connection = br.readLine().split(" ");
            adj[Integer.parseInt(connection[0])].add(Integer.parseInt(connection[1]));
        }
        
        for(int k = 1;k<N+1;k++){
            unVisited[k] = true;
        }
        for(int e=1;e<N+1;e++){
            if(!visited[e]){
                detectCycle(e,adj);
            }
        }
        if(cycle){
            System.out.println("N");
        }
        else{
            System.out.println("Y");
        }
    }
}