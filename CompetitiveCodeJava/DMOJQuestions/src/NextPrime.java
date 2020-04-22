import java.io.*;
/**
 * NextPrime
 */
public class NextPrime {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        while(true){
            if(N==1){
                System.out.println(2);
                break;
            }
            int end = (int)Math.ceil(Math.sqrt(N))+1;
            boolean undivisible = true;
            for(int i = 2;i<end;i++){
                if(N%i==0 && i!=N){
                    undivisible = false;
                    break;
                }
            }
            if(undivisible){
                System.out.println(N);
                break;
            }
            else{
                N+=1;
            }
        }


    }
}