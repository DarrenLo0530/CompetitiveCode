import java.io.*;
import java.util.*;
/**
 * Knapsack1
 */
public class Knapsack1 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int items = Integer.parseInt(in[0]);
        int sacCap = Integer.parseInt(in[1]);

        int[] V = new int[items];
        int[] W = new int[items];



        for(int i = 0; i<items; i++){
            String[] temp = br.readLine().split(" ");
            W[i] = Integer.parseInt(temp[0]);
            V[i] = Integer.parseInt(temp[1]);
        }

        double[] dp = new double[sacCap+1];
        Arrays.fill(dp,-1);
        dp[0] = 0;
        for(int j = 0; j<items; j++){
            for(int i = sacCap-W[j]; i>=0; i--){
                if(dp[i+W[j]]<(dp[i]+V[j]) && dp[i]!=-1){
                    dp[i+W[j]] = dp[i] + V[j];
                }
            }
        }
        
        double max = 0;

    
        for(double i:dp){
            if(i!=-1){
                max = Math.max(i,max);
            }
        }
        System.out.printf("%.0f",max);
            
    }
}