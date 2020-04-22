import java.io.*;
/**
 * BankNotes
 */
public class BankNotes {
    static int[] b, c;
    static int k, N;

    public static void bank(int[] dp){
        for(int i = 0; i<N; i++){//All denominations
            boolean[] newlyAdded = new boolean[k+1];
            for(int j = 1; j<c[i]+1; j++){ //All remaining
                for(int f =0; f+b[i]*j<k+1;f++){ //From all spaces
                    if(dp[f]!=-1 && !newlyAdded[f]){
                        if(dp[f+b[i]*j] == -1 || dp[f]+1*j< dp[f+b[i]*j]){
                            dp[f+b[i]*j] = dp[f]+1*j;
                            newlyAdded[f+b[i]*j] = true;
                            if((f+b[i]*j) == k){
                                return;
                            } 
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        b = new int[N];
        c = new int[N];
        String[] temp1 = br.readLine().split(" ");
        String[] temp2 = br.readLine().split(" ");
        for(int i = 0; i<N; i++){
            b[i] = Integer.parseInt(temp1[N-i-1]);
            c[i] = Integer.parseInt(temp2[N-i-1]);
        }
        k = Integer.parseInt(br.readLine());

        int[] dp = new int[k+1];
        for(int i = 1; i<k+1; i++){
            dp[i] = -1;
        }   
        bank(dp);

        System.out.println(dp[k]);
    }
}