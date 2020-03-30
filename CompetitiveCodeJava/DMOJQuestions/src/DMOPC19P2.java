import java.io.*;
import java.math.BigInteger;
/**
 * DMOPC19P2
 */
public class DMOPC19P2 {
    public static BigInteger factorial(int x){
        if(x == 0){
            return BigInteger.valueOf(1);
        }  
        BigInteger res = BigInteger.valueOf(1);
        for(int i = 1; i <= x; i++){
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger result = BigInteger.valueOf(0);
        String[] temp = br.readLine().split(" ");
        int N = Integer.parseInt(temp[0]);
        int K = Integer.parseInt(temp[1]);
        int[] times = new int[26];
        String word = br.readLine();
        for(int i = 0; i<N; i++){
            if(word.charAt(i) != '*'){
                times[(int) word.charAt(i) - 97] += 1;
            }
        }

        BigInteger fact = factorial(N);

        if(K>0){
            for(int i = 0; i<26; i++){
                if(K>1){
                    for(int k = i; k<26; k++){
                        BigInteger inter = fact;
                        for(int e = 0; e<26; e++){
                            if(e == k && e == i){
                                inter = inter.divide(factorial(times[e]+2));
                            }
                            else if((e == k && e != i)||(e != k && e == i)){
                                inter = inter.divide(factorial(times[e]+1));
                            }
                            else{
                                inter = inter.divide(factorial(times[e]));
                            }
                        }
                        result = result.add(inter);
                    }
                }

                else{
                    BigInteger inter = fact;
                    for(int k = 0; k<26; k++){
                        if(i==k){
                            inter = inter.divide(factorial(times[k]+1));
                        }
                        else{
                            inter = inter.divide(factorial(times[k]));
                        }
                    }
                    result = result.add(inter);
                }
            }
        }

        else{
            BigInteger inter = fact;
            for(int i = 0; i<26; i++){
                inter = inter.divide(factorial(times[i]));
            }

            result = result.add(inter);
        }

        System.out.print(result);
    }
}