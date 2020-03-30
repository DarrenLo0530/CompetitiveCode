/**
 * S3
 */
import java.io.*;
import java.util.*;

public class CCC20S3 {
    static String N, H;
    static Set<Long> usedPatterns = new HashSet<>();

    public static boolean equal(int[] arr1, int[] arr2){
        for(int i =0; i<26; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = br.readLine();
        H = br.readLine();
        int p = 257;
        long mod = 10000000007L;
        long power = 1;
        long currHash = 0;

        int[] letters = new int[26];
        int[] bigWordLetters = new int[26];

        for(int i = 0; i<N.length(); i++){
            letters[(int)N.charAt(i) - 97]++;
        }

        for (int j = 0; j < N.length(); j++)
            power = (power * p) % mod;

        if(H.length()>=N.length()){
            for(int i = 0; i<N.length(); i++){
                currHash = currHash*p + H.charAt(i);
                currHash %= mod;
            }
            
            for(int i = 0; i<N.length();i++){
                bigWordLetters[H.charAt(i) - 97]++;
            }
            
            if(equal(letters, bigWordLetters)){
                usedPatterns.add(currHash);
            }

            for(int i = 1; i<=H.length()-N.length(); i++){

                bigWordLetters[H.charAt(i-1) - 97]--;
                bigWordLetters[H.charAt(i+N.length()-1) - 97]++;

                //Slide
                currHash = currHash*p + H.charAt(i+N.length()-1);
                currHash %= mod;
                currHash -= H.charAt(i-1)*power % mod;

                if(currHash<0){
                    currHash += mod;
                }

                if(equal(letters, bigWordLetters)){
                    usedPatterns.add(currHash);
                }
            }
            
            System.out.println(usedPatterns.size());
        }
        else{
            System.out.println(0);
        }

        
    
    }
}