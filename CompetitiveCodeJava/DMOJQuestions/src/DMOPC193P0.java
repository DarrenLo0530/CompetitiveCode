import java.io.*;
/**
 * DMOPC193P0
 */
public class DMOPC193P0 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = 0;i<N;i++){
            boolean geometric = true;
            boolean arithmetic = true;
            String[] temp = br.readLine().split(" ");
            int[] sequence = new int[temp.length];
            for(int k = 0; k<temp.length;k++){
                sequence[k] = Integer.parseInt(temp[k]);
            }   
            int d = sequence[1] - sequence[0]; 
            
            for(int e = 1;e<sequence.length;e++){
                if(!(sequence[e]-sequence[e-1] == d)){
                    arithmetic = false;
                    break;
                }
            }

            for(int k = 1;k<sequence.length-1;k++){
                if(!(sequence[k]*sequence[k] == sequence[k-1]*sequence[k+1])){
                    geometric = false;
                    break;
                }
            }

            if(geometric && arithmetic){
                System.out.println("both");
            }
            else if(geometric){
                System.out.println("geometric");
            }
            else if(arithmetic){
                System.out.println("arithmetic");
            }
            else{
                System.out.println("neither");
            }
        }

    }
}