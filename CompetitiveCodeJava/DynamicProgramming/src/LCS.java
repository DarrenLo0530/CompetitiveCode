import java.io.*;
/**
 * LCS
 */
public class LCS {
    static String s, t;
    static int[][] dp;
    static String word = "";
    public static void getString(int x, int y){
        while(true){
            if(y==0 || x==0){
                break;
            }
            if(dp[y][x] == dp[y-1][x]){
                y-=1;
            }
            else if(dp[y][x] == dp[y][x-1]){
                x-=1;
            }
            else{
                word = s.charAt(y-1) + word;
                break;
            }
        }

        if(x>1 && y>1){
            getString(x-1, y-1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
        t = br.readLine();
        dp = new int[s.length() + 1][t.length() + 1];
        for(int i = 1; i<s.length()+1; i++){
            for(int k = 1; k<t.length()+1; k++){
                if(s.charAt(i-1) == t.charAt(k-1)){
                    dp[i][k] = 1 + dp[i-1][k-1];
                }
                else{
                    dp[i][k] = Math.max(dp[i-1][k], dp[i][k-1]);
                }
            }
        }
        getString(t.length(), s.length());
        System.out.println(word);
    }

}