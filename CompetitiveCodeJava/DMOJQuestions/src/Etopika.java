     /*
     * Etopika
     */
    import java.io.*;
    import java.util.*;

    public class Etopika {
        static class Node{
            int weight;
            int dest;
            Node(int dest, int weight){
                this.dest = dest;
                this.weight = weight;
            }
        }
        //Node 1 to all other nodes
        //Dist from node A to node B is dist from node 1 to node A + node1 to nodeB
        //This works since all nodes are guranteed to be connected to node A and there are np
        public static int[][] shortestPath(ArrayList<Node>[] tree, int N){
            int[][] sp = new int[N+1][N+1];
            
            for(int i = 1; i<=N; i++){
                boolean[] visited = new boolean[N+1];
                Stack<Node> toVisit = new Stack<>();
                toVisit.push(new Node(i, 0));

                while(!toVisit.isEmpty()){
                    Node curr = toVisit.pop();
                    visited[curr.dest] = true;

                    for(Node j: tree[curr.dest]){
                        if(!visited[j.dest]){
                            sp[i][j.dest] = curr.weight + j.weight;
                            toVisit.add(new Node(j.dest, curr.weight + j.weight));
                        }
                    }
                }
            }

            return sp;
        }
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            String[] in1 = br.readLine().split(" ");
            int N = Integer.parseInt(in1[0]);
            int D = Integer.parseInt(in1[1]);

            ArrayList<Node>[] tree = new ArrayList[N+1];

            for(int i = 0; i<N+1; i++){
                tree[i] = new ArrayList<>();
            }

            for(int i = 0; i<N-1; i++){
                String[] in2 = br.readLine().split(" ");
                int a = Integer.parseInt(in2[0]);
                int b = Integer.parseInt(in2[1]);
                int c = Integer.parseInt(in2[2]);

                tree[a].add(new Node(b, c));
                tree[b].add(new Node(a, c));
            }

            int[][] sp = shortestPath(tree, N);

            long[] dp = new long[3];
            int prevb1 = 1;
            int prevb2 = 1;

            for(int i = 1; i<=D; i++){
                String[] in2 = br.readLine().split(" ");
                int b1 = Integer.parseInt(in2[0]);
                int b2 = Integer.parseInt(in2[1]);
                long newVal1 = Math.min(dp[1] + sp[prevb1][b1], dp[2] + sp[prevb2][b1]) + sp[b1][b2];
                long newVal2 = Math.min(dp[1] + sp[prevb1][b2], dp[2] + sp[prevb2][b2]) + sp[b2][b1];
                dp[1] = newVal1;
                dp[2] = newVal2;

                prevb1 = b2;
                prevb2 = b1;
            }
            System.out.println(Math.min(dp[1], dp[2]));
        }
    }