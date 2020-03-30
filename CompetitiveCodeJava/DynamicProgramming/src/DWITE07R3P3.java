import java.io.*;
import java.util.*;

/**
 * DWITE07R3P3
 */
public class DWITE07R3P3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int k = 0; k<5; k++){
            int space = Integer.parseInt(br.readLine());
            int numSongs = Integer.parseInt(br.readLine());

            int[] N = new int[numSongs];
            int[] S = new int[numSongs];

            for(int i = 0; i<numSongs; i++){
                String[] temp = br.readLine().split(" ");
                N[i] = Integer.parseInt(temp[1]);
                S[i] = Integer.parseInt(temp[2]);
            }

            int[] dp = new int[space+1];
            Arrays.fill(dp,-1);
            dp[0] = 0;
            for(int i = 0; i<numSongs; i++){
                boolean[] justAdded = new boolean[space+1];
                for(int e = space; e>=0; e--){
                    if(dp[e]!=-1 && !justAdded[e] && e+S[i] < space+1){
                        if(dp[e+S[i]] < dp[e] + N[i]){
                            justAdded[e] = true;
                            dp[e+S[i]] = dp[e] + N[i];
                        }
                    }
                }
            }
            int max = 0;
            for(int e = 0; e<space+1; e++){
                max = Math.max(max,dp[e]);
            }

            System.out.println(max);
        }
    }
}