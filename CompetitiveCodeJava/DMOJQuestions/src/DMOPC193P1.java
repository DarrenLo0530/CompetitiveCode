import java.io.*;
import java.util.*;
/**
 * DMOPC191P0
 */
public class DMOPC193P1 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] temp = br.readLine().split(" ");
        int[] times = new int[200001];
        int min = 0;
        int max = 0;
        for(int k = 0;k<N;k++){
            int number = Integer.parseInt(temp[k]);
            if(number<min){
                min = number;
            }
            if(number>max){
                max = number;
            }
            times[number+100000]+=1;
        }
        int modeNum = 0;
        ArrayList<Integer> mode = new ArrayList<>();
        for(int e = min+100000;e<max+100001;e++){
            if(times[e]>modeNum){
                modeNum = times[e];
                mode.clear();
                mode.add(e-100000);
            }
            else if(times[e] == modeNum){
                mode.add(e-100000);
            }
        }

        Collections.sort(mode);
        for(int i:mode){
            System.out.print(i + " ");
        }

    }
}