import java.io.*;
import java.util.*;
/**
 * CCC06J4 - It's tough being a teen(Topological sort)
 */
public class CCC06J4 {
    static boolean cycle = false;

    public static void find(ArrayList<ArrayList<Integer>> adj, Stack<Integer> order, boolean[] visited, int current){
        visited[current] = true;
        if(!order.contains(current)){
            for(int i = 0;i<adj.get(current).size();i++){
                if(visited[adj.get(current).get(i)]){
                    cycle = true;
                }
                else{
                    find(adj,order,visited,adj.get(current).get(i));
                }
            }
            order.push(current);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        for(int i = 0;i<7;i++){
            adj.add(new ArrayList<Integer>());
        }
        adj.get(0).add(6);
        adj.get(0).add(3);
        adj.get(1).add(0);
        adj.get(2).add(3);
        adj.get(2).add(4);
        
        while(true){
            int from = Integer.parseInt(br.readLine());
            int to = Integer.parseInt(br.readLine());
            if(from == 0 && to == 0){
                break;
            }
            else{
                adj.get(from-1).add(to-1);
            }
        }

        for(ArrayList<Integer> e:adj){
            Collections.sort(e);
            Collections.reverse(e);
        }


        Stack<Integer> order = new Stack<>();
        for(int q = 6;q>=0;q--){
            boolean[] visited = new boolean[7];
            find(adj,order,visited,q);
        }

        if(cycle){
            System.out.println("Cannot complete these tasks. Going to bed.");
        }
        else{
            while(order.size()>0){
                System.out.print(Integer.toString(order.pop()+1) + " ");
            }
        }
    }
}