import java.io.*;
/**
 * CCC19J4
 */
public class CCC19J4 {

    public static boolean correct(String[][] flowers, int N){
        for(int k = 0;k<N;k++){//column
            for(int v = 0;v<N-1;v++){//row
                if(Integer.parseInt(flowers[v][k])>Integer.parseInt(flowers[v+1][k])){
                    return false;
                }
                else if(Integer.parseInt(flowers[k][v])>Integer.parseInt(flowers[k][v+1])){
                    return false;
                }
            }             
        }
        return true;
    }

    public static String[][] rotate(String[][] flowers,int N){
        String[][] rotated = new String[N][N];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                rotated[c][N-1-r] = flowers[r][c];
            }
        }    
        return rotated;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[][] flowers = new String[N][N];
        for(int i = 0; i < N;i++){
            String x  = br.readLine();
            String[] flowerHeight = x.split(" ");
            flowers[i] = flowerHeight;
        }

        for(int j = 0;j<4;j++){
            boolean isCorrect = correct(flowers,N);
            
            if(isCorrect == true){
                break;
            }

            else{
                flowers = rotate(flowers,N);
            }  
        }
        for(int g = 0;g<N;g++){
            for(int h = 0;h<N;h++){
                if(h+1 == N){
                    System.out.println(flowers[g][h] + " ");
                }
                else{
                    System.out.print(flowers[g][h] + " ");
                }
            }
        }
        

    }   
}