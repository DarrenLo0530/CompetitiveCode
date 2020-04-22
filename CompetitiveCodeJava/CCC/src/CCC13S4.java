import java.io.*;
import java.util.*;

/**
 * CCC13S4 -- Who is taller?
 */
public class CCC13S4 {
    static int N;

    public static boolean BFS(int first,int last, ArrayList<Integer>[] adj){
        Stack<Integer> toVisit = new Stack<>();
        boolean visited[] = new boolean[N+1];
        toVisit.push(first);
        while(!toVisit.isEmpty()){
            int curr = toVisit.pop();
            visited[curr] = true;
            if(curr == last){
                return true;
            }
            else{
                for(int e:adj[curr]){
                    if(!visited[e]){
                        toVisit.push(e);
                    }
                }
            }
        }
        return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] start = br.readLine().split(" ");

        N = Integer.parseInt(start[0]);
        int M = Integer.parseInt(start[1]);
        ArrayList<Integer>[] adj = new ArrayList[N+1];
        for(int e = 0;e<N+1;e++){
            adj[e] = new ArrayList<>();
        }
        for(int i = 0;i<M;i++){
            String[] comp = br.readLine().split(" ");
            adj[Integer.parseInt(comp[0])].add(Integer.parseInt(comp[1]));
        }

        String[] temp = br.readLine().split(" ");
        int p = Integer.parseInt(temp[0]);
        int q = Integer.parseInt(temp[1]);

        boolean qTaller;
        boolean pTaller = BFS(p,q,adj);
        if(!pTaller){
            qTaller = BFS(q,p,adj);
            if(qTaller){
                System.out.println("no");
            }
            else{
                System.out.println("unknown");
            }
        }
        else{
            System.out.println("yes");
        }
        
    }
}