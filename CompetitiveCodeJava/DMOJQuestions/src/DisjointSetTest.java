/**
 * DisjointSetTest
 */
import java.io.*;
import java.util.*;

class Edge{
    int node1, node2;
    Edge(int node1, int node2){
        this.node1 = node1; 
        this.node2 = node2;
    }
}

public class DisjointSetTest {
    public static int findParent(int v, int[] disjointSet){
        if(disjointSet[v] < 0){
            return v;
        } 
        else{
            int parent = findParent(disjointSet[v], disjointSet);

            disjointSet[v] = parent;
            return parent;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] info = br.readLine().split(" ");
        
        int N = Integer.parseInt(info[0]);
        int M = Integer.parseInt(info[1]);

        int[] disjointSet = new int[N+1];
        Arrays.fill(disjointSet, -1);

        Edge[] edges = new Edge[M];
        boolean[] edgeIn = new boolean[M+1];


        for(int i = 0; i<M; i++){
            String[] edgeInfo = br.readLine().split(" ");
            edges[i] = new Edge(Integer.parseInt(edgeInfo[0]), Integer.parseInt(edgeInfo[1]));
        }

        for(int i = 0; i<M; i++){
            Edge curr = edges[i];
            int parent1 = findParent(curr.node1, disjointSet);
            int parent2 = findParent(curr.node2, disjointSet);
            if(parent1 != parent2){
                edgeIn[i+1] = true;
                if(disjointSet[parent1] <= disjointSet[parent2]){
                    disjointSet[parent1] += disjointSet[parent2];
                    disjointSet[parent2] = parent1;
                }
                else{
                    disjointSet[parent2] += disjointSet[parent1];
                    disjointSet[parent1] = parent2;
                }
            }
        }

        int parentCounter = 0;
        for(int i = 1; i<N+1; i++){
            if(disjointSet[i] < 0){
                parentCounter++;
            }
        }

        if(parentCounter != 1){
            System.out.println("Disconnected Graph");
        }

        else{
            for(int i = 0; i<M+1; i++){
                if(edgeIn[i]){
                    System.out.println(i);
                }
            }
        }
    }
}