import java.io.*;

/**
 * CCC12S5
 */

public class CCC12S5 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] movement = {{1, 0}, {0, 1}};

        String[] dimensions = br.readLine().split(" ");
        int R = Integer.parseInt(dimensions[0]);
        int C = Integer.parseInt(dimensions[1]);
        int N = Integer.parseInt(br.readLine());

        int dp[][] = new int[R + 1][C + 1];
        dp[1][1] = 1;

        for(int i = 0; i < N; i++){
            String[] catLocation = br.readLine().split(" ");
            dp[Integer.parseInt(catLocation[0])][Integer.parseInt(catLocation[1])] = -1;
        }


        //i is y, k is x
        for(int i = 1; i < R+1; i++){
            for(int k = 1; k < C+1; k++){
                if(dp[i][k] == -1){
                    continue;
                }
                for(int[] move: movement){
                    int newK = k + move[0]; 
                    int newI = i + move[1];
                    if(newI < R+1 && newK < C+1){
                        if(dp[newI][newK] != -1){
                            dp[newI][newK] += dp[i][k];
                        }
                    }
                }
            }
        }
        System.out.println(dp[R][C]);

        
    }
}