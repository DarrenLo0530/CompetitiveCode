import java.io.*;
import java.util.*;

/**
 * CCC00S4 - Golf
 */
public class CCC00S4 {
    static int N;
    static int distance;

    public static void copy(int size, int[] list1, int[] list2){
        for(int i = 0;i<size;i++){
            list1[i]  = list2[i];
        }
    }
    public static boolean getDistance(int[] clubs, int[]minStrokes){
        int[] tempStrokes = new int[distance+1];
        copy(distance+1,tempStrokes,minStrokes);

        for(int e = 0;e<distance+1;e++){
            if(minStrokes[e]!=0){
                int k = e;
                while(k+e<distance+1){
                    if(minStrokes[k]!=0){
                        if(tempStrokes[e+k] == 0){
                            tempStrokes[e+k] = minStrokes[k]+minStrokes[e]; 
                        }
                        else if(tempStrokes[e+k] > 0 && minStrokes[k]+minStrokes[e]<tempStrokes[e+k]){
                            tempStrokes[e+k] = minStrokes[k]+minStrokes[e]; 
                        }
                        if(e+k == distance){
                            copy(distance+1,minStrokes,tempStrokes);
                            return true;
                        }
                    }
                    k++;
                }
            }
        }
        copy(distance+1,minStrokes,tempStrokes);
        return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        distance = Integer.parseInt(br.readLine());
        N = Integer.parseInt(br.readLine());

        int[] clubs = new int[N];
        for(int i = 0;i<N;i++){
            clubs[i] = Integer.parseInt(br.readLine());   
        }
        Arrays.sort(clubs);

        int[] minStrokes = new int[distance+1];
        for(int e:clubs){
            minStrokes[e] = 1;
        }
        for(int i = 0;i<Math.ceil(distance/clubs[0]);i++){
            boolean result = getDistance(clubs,minStrokes);
            if(result){
                break;
            }
        }

        if(minStrokes[distance]!=0){
            System.out.println("Roberta wins in " + minStrokes[distance] + " strokes.");
        }
        else{
            System.out.println("Roberta acknowledges defeat.");
        }
    
    }
}