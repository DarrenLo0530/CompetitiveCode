import java.io.*;
import java.util.*;
/**
 * Frog1
 */
public class Frog1 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] temp = br.readLine().split(" ");
        int[] heights = new int[N];
        for(int i = 0; i<N; i++){
            heights[i] = Integer.parseInt(temp[i]);
        }

        int dp[] = new int[N];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        
        for(int i = 0; i<N; i++){
            if(i+1<N){
                dp[i+1] = Math.min(dp[i+1], Math.abs(heights[i] - heights[i+1]) + dp[i]);
            }
            if(i+2<N){
                dp[i+2] = Math.min(dp[i+2],  Math.abs(heights[i] - heights[i+2]) + dp[i]);
            }
        }
        System.out.println(dp[N-1]);
    }
}