import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


/**
 * CCC17S3
 */
public class CCC17S3 {

    public static void main(String[] args) throws IOException{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int N = Integer.parseInt(br.readLine());
      int[] temp = new int[2001];
      int[] length = new int[4001];
      String Ltemp[] = br.readLine().split(" ");
      for(int k = 0;k<N;k++){
        temp[Integer.parseInt(Ltemp[k])] +=1;
      }
      for(int i = 0;i<2001;i++){
        if(temp[i]>0){
          for(int e = i;e<2001;e++){
            if(e==i){
              length[e+i] += (int)Math.floor(temp[e]/2);
            }
            else if(temp[e]>0){
              length[i+e] += Math.min(temp[e],temp[i]);
            }
          }
        }
      }
    int a1 = 0;
    int a2 = 0;
    for(int f = 0;f<4001;f++){
      if(length[f]>a1){
        a1 = length[f];
        a2 = 1;
      }
      else if(length[f]==a1){
        a2+=1;
      }
    }
    System.out.println(Integer.toString(a1) + " " + Integer.toString(a2));
  }
}