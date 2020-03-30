/**
 * SumOfPrimes
 */
import java.io.*;
import java.util.*;

public class SumOfPrimes {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] prime = new boolean[10000001];
        Arrays.fill(prime, true);
        prime[1] = false;
        for(int i = 2; i<Math.sqrt(10000000)+1; i++){
            if(prime[i] == true){
                for(int k = 2; k*i < 10000000l; k++){
                    prime[k*i] = false;
                }
            }
        }

        for(int i = 0; i<5; i++){
            int num = Integer.parseInt(br.readLine());

            if(num%2 == 0){
                for(int k = (int) Math.ceil(num/2)+1; k>=3; k--){
                    if(prime[k] && prime[num-k]){
                        System.out.printf("%d = %d + %d\n", num, Math.min(k, num-k), Math.max(k ,num-k));
                        break;
                    }
                }
            } else {
                if(prime[num]){
                    System.out.printf("%d = %d\n", num, num);
                } else {
                    boolean solved = false;
                    for(int k = (int) Math.floor(num/3); !solved && k>=3; k--){
                        for(int e = (int) Math.ceil((num-k)/2)+1; !solved && e>=3; e--){
                            if(prime[k] && prime[e] && prime[num-k-e] && k <= e && e <= num-k-e){
                                System.out.printf("%d = %d + %d + %d\n", num, k, e, num-k-e);
                                solved = true;
                            }
                        }
                    }
                }
            }
            
        }
    }
}