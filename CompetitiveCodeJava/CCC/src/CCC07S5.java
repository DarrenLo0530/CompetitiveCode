import java.io.*;
/**
 * CCC07S5
 */
public class CCC07S5 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            String[] temp = br.readLine().split(" ");
            int numPins = Integer.parseInt(temp[0]);
            int numBalls = Integer.parseInt(temp[1]);
            int ballWidth = Integer.parseInt(temp[2]);            
            
            int[] vals = new int[numPins];
            for(int k = 0; k < numPins; k++){
                vals[k] = Integer.parseInt(br.readLine());
            }

            int[][] dp = new int[numBalls + 1][numPins];

            for(int a = 1; a<numBalls+1; a++){
                for(int b = 0; b<numPins; b++){
                    if(b < ballWidth){
                        for(int x = 0; x<=b; x++){
                            dp[a][b] += vals[x];
                        }
                    }
                    else{
                        int group = 0;
                        for(int x = b-ballWidth+1; x<b+1; x++){
                            group += vals[x];
                        }
                        dp[a][b] = Math.max(dp[a][b-1], group + dp[a-1][b-ballWidth]);
                    }
                }
            }   

            System.out.println(dp[numBalls][numPins-1]);

        }
        
    }
}