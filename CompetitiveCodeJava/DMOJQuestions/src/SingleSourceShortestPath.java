import java.io.*;
import java.util.*;

/**
 * SingleSourceShortestPath
 */

public class SingleSourceShortestPath{

    static class Node{
        int value;
        int dist;

        Node(int value, int dist){
            this.value = value;
            this.dist = dist;
        }
    }

    static class Edge{
        int node1;
        int node2;
        int weight;

        Edge(int node1, int node2, int weight){
            this.node1 = node1;
            this.node2 = node2; 
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] info = br.readLine().split(" ");
        int N = Integer.parseInt(info[0]);
        int M = Integer.parseInt(info[1]);
        Edge[] edges = new Edge[M];
        for(int i = 0; i<M; i++){
            String[] edgeInfo = br.readLine().split(" ");
            edges[i] = new Edge(Integer.parseInt(edgeInfo[0]), Integer.parseInt(edgeInfo[1]), Integer.parseInt(edgeInfo[2]));
        }
        boolean[] visited = new boolean[N+1];
        int dist[] = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;

        PriorityQueue<Node> pQueue = new PriorityQueue<>(new Comparator<Node>() {
            public int compare(Node node1, Node node2){
                return node1.dist-node2.dist;
            }
        });
        pQueue.add(new Node(1, 0));

        while(!pQueue.isEmpty()){
            Node currNode = pQueue.poll();
            if(!visited[currNode.value]){
                visited[currNode.value] = true;
                for(Edge i: edges){
                    if(i.node1 == currNode.value){
                        if(dist[i.node2] > dist[i.node1] + i.weight){
                            dist[i.node2] = dist[i.node1] + i.weight;
                            pQueue.add(new Node(i.node2, dist[i.node1] + i.weight));
                        }
                    }
                    else if(i.node2 == currNode.value){
                        if(dist[i.node1] > dist[i.node2] + i.weight){
                            dist[i.node1] = dist[i.node2] + i.weight;
                            pQueue.add(new Node(i.node1, dist[i.node2] + i.weight));
                        }
                    }
                    
                }
            }
        }

        for(int i = 1; i<N+1; i++){
            if(dist[i] == Integer.MAX_VALUE){
                System.out.println("-1");
            }
            else{
                System.out.println(dist[i]);
            }
        }

    }
}