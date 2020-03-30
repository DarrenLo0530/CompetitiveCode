import java.io.*;
/**
 * DMOPC161P3
 */
public class DMOPC161P3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        double[] shoes = new double[N+1];
        double[] minPrice = new double[N+1];
        for(int i = 1; i<N+1; i++){
            minPrice[i] = Double.MAX_VALUE;
        }
        String[] temp = br.readLine().split(" ");
        for(int i = 0; i<N; i++){
            shoes[i+1] = Double.parseDouble(temp[i]);
        }

        for(int i = 1; i<N+1; i++){
            //One shoe without any deal
            if(minPrice[i] > shoes[i] + minPrice[i-1]){
                minPrice[i] = shoes[i] + minPrice[i-1];
            }
        
            //Two shoes
            if(i+1<N+1){
                if(shoes[i] <= shoes[i+1] && minPrice[i+1] > minPrice[i-1] + shoes[i]/2 + shoes[i+1]){
                    minPrice[i+1] = minPrice[i-1] + shoes[i]/2 + shoes[i+1];
                }
                else if(shoes[i+1] <= shoes[i] && minPrice[i+1] > minPrice[i-1] + shoes[i+1]/2 + shoes[i]){
                    minPrice[i+1] = minPrice[i-1] + shoes[i+1]/2 + shoes[i];
                }
            }
            //Three shoes
            if(i+2<N+1){
                if(shoes[i] <= shoes[i+1] && shoes[i] <= shoes[i+2] && minPrice[i+2] > minPrice[i-1] + shoes[i+1] + shoes[i+2]){
                    minPrice[i+2] = minPrice[i-1] + shoes[i+1] + shoes[i+2];
                }
                else if(shoes[i+1] <= shoes[i] && shoes[i+1] <= shoes[i+2] && minPrice[i+2] > minPrice[i-1] + shoes[i] + shoes[i+2]){
                    minPrice[i+2] = minPrice[i-1] + shoes[i] + shoes[i+2];
                }
                else if(shoes[i+2] <= shoes[i+1] && shoes[i+2] <= shoes[i] && minPrice[i+2] > minPrice[i-1] + shoes[i+1] + shoes[i]){
                    minPrice[i+2] = minPrice[i-1] + shoes[i+1] + shoes[i];
                }
            }
        }

        System.out.printf("%.1f", minPrice[N]);

    }
}