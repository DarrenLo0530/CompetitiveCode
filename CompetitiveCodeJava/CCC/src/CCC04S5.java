import java.io.*;
/**
 * CCC04S5
 */
public class CCC04S5 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        while(true){
            String gridSize = br.readLine();
            if(gridSize.equals("0 0")){
                break;
            }
            int n = Integer.parseInt(gridSize.split(" ")[0]);
            int m = Integer.parseInt(gridSize.split(" ")[1]);
            int[][] grid = new int[n][m];
            int[][] dp = new int[n][m];

            for(int i = 0; i<n; i++){
                String line = br.readLine();
                for(int j = 0; j<m; j++){
                    Character temp = line.charAt(j);
                    if(temp.equals('.')){
                        grid[i][j] = 0;
                    }
                    else if(temp.equals('*')){
                        grid[i][j] = -1;
                    }
                    else{
                        grid[i][j] = Integer.parseInt(String.valueOf(temp));
                    }
                }
            }
            
            dp[n-1][0] = grid[n-1][0];
            
            
            for(int i = n-2; i>=0; i--){
                if(grid[i][0]<0){
                    break;
                }
                else{
                    dp[i][0] = dp[i+1][0] + grid[i][0];
                }
            }

            for(int i = 1; i<m; i++){ //columns
                for(int j = 0; j<n; j++){ //starting from each row
                    int curr = dp[j][i-1];
                    if(!(grid[j][i-1]<0)){
                        for(int k = j; k<n; k++){//going down
                            if(grid[k][i]<0){
                                break;
                            }
                            else{
                                curr+=grid[k][i];
                                dp[k][i] = Math.max(dp[k][i], curr);
                            }
                        }
                    }
                    
                }
           
                for(int j = n-1; j>=0; j--){
                    int curr = dp[j][i-1];
                    if(!(grid[j][i-1]<0)){
                        for(int k = j; k>=0; k--){//going up
                            if(grid[k][i]<0){
                                break;
                            }
                            else{
                                curr+=grid[k][i];
                                dp[k][i] = Math.max(dp[k][i], curr);
                            }
                        }
                    }   
                }
            }            
            System.out.println(Integer.toString(dp[n-1][m-1])); 
        }
    }
}