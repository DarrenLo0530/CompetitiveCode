/**
 * CCC03S5
 */
import java.io.*;
import java.util.*;

class WeightedValue{
    int val, weight;
    WeightedValue(int val, int weight){
        this.val = val;
        this.weight = weight;
    }
}

public class CCC03S5 {
    static int c, r, d;

    public static void findMaxWeight(ArrayList<WeightedValue>[] adjacencyList, int[] maxWeight, int[] destinations){

        PriorityQueue<WeightedValue> pq = new PriorityQueue<>(new Comparator<WeightedValue>(){
            public int compare(WeightedValue v1, WeightedValue v2){
                return v2.weight - v1.weight;
            }
        });

        pq.add(new WeightedValue(1, Integer.MAX_VALUE));

        boolean[] visited = new boolean[c+1];
        while(!pq.isEmpty()){
            WeightedValue next = pq.poll();
            if(!visited[next.val]){
                visited[next.val] = true;

                for(WeightedValue i: adjacencyList[next.val]){
                    if(!visited[i.val]){
                        int currMax = Math.max(Math.min(i.weight, next.weight), maxWeight[i.val]);
                        maxWeight[i.val] = currMax;
                        pq.add(new WeightedValue(i.val, currMax));
                    }
                }
            }

        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] graphInfo = br.readLine().split(" ");
        c = Integer.parseInt(graphInfo[0]);
        r = Integer.parseInt(graphInfo[1]);
        d = Integer.parseInt(graphInfo[2]);

        ArrayList<WeightedValue>[] adjacencyList = new ArrayList[c+1];
        int[] destinations = new int[d];

        for(int i = 0; i < c+1; i++){
            adjacencyList[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < r; i++){
            String[] roadInfo = br.readLine().split(" ");
            int x = Integer.parseInt(roadInfo[0]);
            int y = Integer.parseInt(roadInfo[1]);
            int z = Integer.parseInt(roadInfo[2]);

            adjacencyList[y].add(new WeightedValue(x, z));
            adjacencyList[x].add(new WeightedValue(y, z));
        }

        for(int i = 0; i < d; i++){
            destinations[i] = Integer.parseInt(br.readLine());
        }

        int[] maxWeight = new int[c+1];
        Arrays.fill(maxWeight, -1);
        maxWeight[1] = Integer.MAX_VALUE;

        findMaxWeight(adjacencyList, maxWeight, destinations);

        int ans = Integer.MAX_VALUE;
        for(int i: destinations){
            ans = Math.min(maxWeight[i], ans);
        }


        System.out.println(ans);
    }
}