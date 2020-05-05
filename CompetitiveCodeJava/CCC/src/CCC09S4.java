import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CCC09S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int T = Integer.parseInt(br.readLine());

    
        int[][] graph = new int[N+1][N+1];
        int[] shortestPath = new int[N+1];
        boolean[] visited = new boolean[N+1];
        int[] pencilCost = new int[N+1];

        Arrays.fill(shortestPath, Integer.MAX_VALUE);
        Arrays.fill(pencilCost, -1);

        int x, y, c;
        for(int i = 0; i<T; i++){
            String next[] = br.readLine().split(" ");
            x = Integer.parseInt(next[0]);
            y = Integer.parseInt(next[1]);
            c = Integer.parseInt(next[2]);
            
            graph[x][y] = graph[x][y] == 0 ? c :  Math.min(graph[x][y], c);
            graph[y][x] = graph[y][x] == 0 ? c : Math.min(graph[y][x], c);
        }

        int K = Integer.parseInt(br.readLine());
        for(int i = 0; i<K; i++){
            String next[] = br.readLine().split(" ");
            x = Integer.parseInt(next[0]);
            pencilCost[x] = Integer.parseInt(next[1]);
        }

        int D = Integer.parseInt(br.readLine());

        shortestPath[D] = 0;
        int visiting = D;

        while(visiting != -1){
            visited[visiting] = true;

            for(int i = 1; i<=N; i++){
                if(graph[visiting][i] != 0){
                    shortestPath[i] = Math.min(shortestPath[i], shortestPath[visiting] + graph[visiting][i]);
                }
            }

            int minDist = Integer.MAX_VALUE;
            int minIndex = -1;

            for(int i = 1; i<=N; i++){
                if(!visited[i] && shortestPath[i] < minDist){
                    minDist = shortestPath[i];
                    minIndex = i;
                }
            }

            visiting = minIndex;
        }


        int minCost = Integer.MAX_VALUE;
        for(int i = 1; i<=N; i++){
            if(pencilCost[i] != -1 && shortestPath[i] != Integer.MAX_VALUE){
                minCost = Math.min(minCost, pencilCost[i] + shortestPath[i]);
            }
        }

        System.out.println(minCost);


    }
}