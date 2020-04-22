import java.io.*;
import java.util.*;
/**
 * GlobeX2019S1
 */
public class GlobeX2019S1 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] temp = br.readLine().split(" ");
        int N = Integer.parseInt(temp[0]);
        int K = Integer.parseInt(temp[1]);
        HashMap<String,Integer> map = new HashMap<>();
        int total = 0;

        
        for(int i = 0; i<N; i++){
            String currPlan = br.readLine();
            if(!map.containsKey(currPlan)){
                System.out.println(0);
                total+=1;
                map.put(currPlan,1);
            }
            else{
                System.out.println(map.get(currPlan));
                map.put(currPlan, map.get(currPlan)+1);
            }
        }
       
        System.out.println(total);
    }
}