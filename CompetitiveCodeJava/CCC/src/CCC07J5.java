import java.io.*;
import java.util.*;

/**
 * CCC07J5 - Keep on Truckin'
 */


public class CCC07J5 {
    static Stack<Integer> next = new Stack<>();

    public static void getPossibilities(Integer hotels[], int[][] distances){

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int A = Integer.parseInt(br.readLine()), B = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());  

        Integer hotelsTemp[] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
        Integer hotels[] = Arrays.copyOf(hotelsTemp,N+14);
        
        for(int i = 14 ;i<N+14;i++){
            hotels[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(hotels);

        long[] possibilities = new long[14+N];
        possibilities[0] = 1;
        
        boolean visited[] = new boolean[14+N];

        ArrayList<Integer> check = new ArrayList<Integer>();
        check.add(0);
        while(check.size()!=0){
            int current = check.get(0);
            visited[current] = true;
            for(int i = current+1;i<N+14;i++){
                if(hotels[i]-hotels[current] >= A && hotels[i]-hotels[current] <=B){
                    if(!visited[i] && !check.contains(i)){
                        check.add(i);
                    }
                    possibilities[i] += possibilities[current];
                }
                else if(hotels[i]-hotels[current] >B){
                    break;
                }
            }
            check.remove(0);
        }
        System.out.println(possibilities[13+N]);

    }
}