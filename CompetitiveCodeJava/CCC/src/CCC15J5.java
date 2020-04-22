/**
 * CCC18S3
 */
import java.io.*;

public class CCC15J5 {
    static int[][][] dp;

    public static int getCombinations(int numPeople, int numPies, int prevPie){


        int maxNum = (int) Math.floor(numPies/numPeople);
        int totalCombinations = 0;

        if(numPeople - 1 <= 0){
            return 1;
        }
        
        if(dp[numPies][numPeople][prevPie] != 0){
            return dp[numPies][numPeople][prevPie];
        }

        else{
            for(int i = prevPie; i < maxNum + 1; i++){
                totalCombinations += getCombinations(numPeople - 1, numPies - i, i);
            }
    
            dp[numPies][numPeople][prevPie] = totalCombinations;
            return totalCombinations;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        dp = new int[n + 1][k + 1][n + 1]; //column is number of people, row is number of pie slices
        System.out.println(getCombinations(k, n, 1));
    }
}