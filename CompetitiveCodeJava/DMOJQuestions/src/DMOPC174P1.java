import java.io.*;

/**
 * DMOPC174P1
 */
public class DMOPC174P1 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = br.readLine().split(" ");
        int length = Integer.parseInt(inputs[0]);
        int strokes = Integer.parseInt(inputs[1]);
        int[] ribbon = new int[length+1];
        int[] difArray = new int[length+1];
        int appeared = 0;

        for(int i = 0; i<strokes;i++){
            String[] lines = br.readLine().split(" ");
            int start = Integer.parseInt(lines[0]);
            int end = Integer.parseInt(lines[1]);
            difArray[start] +=1;
            difArray[end] -= 1;
        }
        for(int j = 0;j<length;j++){
            if(j==0){
                ribbon[j] = difArray[j];
            }
            else{
                ribbon[j] = ribbon[j-1]+difArray[j];
            }
        }
        for(int e:ribbon){
            if(e>=1){
                appeared+=1;
            }
        }
        System.out.println(Integer.toString(length-appeared) + " " + Integer.toString(appeared));
    }
}