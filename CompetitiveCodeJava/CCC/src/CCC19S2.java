import java.io.*;
/**
 * CCC19S2
 */
public class CCC19S2 {
    public static boolean isPrime(int x){
        if(x==1){
            return false;
        }
        if(x==2){
            return true;
        }
        for(int i = 2;i<(int)Math.sqrt(x)+1;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
        
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        for(int i = 0; i<n; i++){
            int curr = 2*Integer.parseInt(br.readLine());
            for(int e=2;e<curr-2;e++){
                if(isPrime(e) && isPrime(curr-e)){
                    System.out.println(Integer.toString(e) + " " + Integer.toString(curr-e));
                    break;
                }
            }
        }

    }
}