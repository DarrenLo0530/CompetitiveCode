/**
 * TourDeForce
 */
import java.util.*;

public class TourDeForce {
    static class Card{
        int score1, score2;
        Card(int score1, int score2){
            this.score1 = score1;
            this.score2 = score2;
        }
    }

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);

        for(int i = 0; i<10; i++){
            int N = sc.nextInt();
            int currVal;
            Card[] cards = new Card[N+1];
            int[] sumArr = new int[N+1];

            for(int j = 1; j<=N; j++){
                int num1 = sc.nextInt();
                int num2 = sc.nextInt();
                cards[j] = new Card(num1, num2);
                sumArr[j] = sumArr[j-1] + num1 + num2;
            }

            int[] dp = new int[N+1];
            for(int j = 1; j<=N; j++){
                for(int k = 0; k<5 && j+k <= N; k++){
                    if(j+k != N || k == 4){
                        currVal = dp[j-1] + sumArr[j+k] - sumArr[j-1] - cards[j+k].score2 - 1; 
                    } else {
                        currVal = dp[j-1] + sumArr[j+k] - sumArr[j-1];
                    }
                    dp[j+k] = Math.max(dp[j+k], currVal);   
                }
            }
            System.out.println(dp[N]);

            
        }
        sc.close();
    }
}