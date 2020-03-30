import java.io.*;
/**
 * CCC08S2
 */
public class CCC08S2 {

    public static double getDist(double x, double y){
        return(Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            int ans = 0;
            int curr = Integer.parseInt(br.readLine());
            if(curr == 0){
                break;
            }
            int end = curr;
            for(int i = 1; i<curr+1; i++){
                for(int k = end; k>=0; k--){
                    if(getDist(i,k)<=curr){
                        ans+=k+1;
                        end = k;
                        break;
                    }
                }
            }
            System.out.println(ans*4+1);
        }
    }
}