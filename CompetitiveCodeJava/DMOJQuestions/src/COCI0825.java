import java.io.*;
import java.math.BigInteger;
/**
 * COCI082#5
 */
public class COCI0825 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();
        BigInteger poss = BigInteger.valueOf(1);
        BigInteger total = BigInteger.valueOf(1);

        for(int i = 0;i<word.length();i++){
            Character walk = word.charAt(i);
            if(walk.equals('L')){
                total = total.multiply(BigInteger.valueOf(2));
            }
            else if(walk.equals('R')){
                total = total.multiply(BigInteger.valueOf(2)).add(poss);               
            }

            else if(walk.equals('*')){
                total = total.multiply(BigInteger.valueOf(5)).add(poss);
                poss = poss.multiply(BigInteger.valueOf(3));
            }            
        }

        System.out.print(total);
    }
}