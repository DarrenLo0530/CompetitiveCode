//CCC '01 S4 - Cookies
import java.io.*;

/**
 * CCC01S4
 */
public class CCC01S4 {

    public static double calculateDistance(int x1,int y1,int x2,int y2){
        double dist = Math.sqrt(Math.pow(x1-x2,2)+Math.pow(y1-y2,2));
        return dist;
    }
        
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] x = new int[n];
        int[] y = new int[n];

        for(int i = 0;i<n;i++){
            String[] pairs = br.readLine().split(" ");
            x[i] = Integer.parseInt(pairs[0]);
            y[i] = Integer.parseInt(pairs[1]);
        }
        double largest = 0;

        for(int i = 0;i<n-2;i++){
            for(int e = i+1;e<n-1;e++){
                for(int q = e+1;q<n;q++){
                    double a = calculateDistance(x[i],y[i],x[e],y[e]);
                    double b = calculateDistance(x[i],y[i],x[q],y[q]);
                    double c = calculateDistance(x[e],y[e],x[q],y[q]);
                    double semi = (a+b+c)/2;
                    if(a*a+b*b-c*c<0 || b*b+c*c-a*a <0 || a*a+c*c-b*b <0){
                       if(Math.max(a,Math.max(b,c)) > largest){
                           largest = Math.max(a,Math.max(b,c));
                       } 
                    }
                    else{
                        double distance = (2*a*b*c)/(4*Math.sqrt(semi*(semi-a)*(semi-b)*(semi-c)));
                        if (distance > largest){
                            largest = distance;
                    }

                    }
                }
            }
        }
        System.out.printf("%.2f", largest);
        
    }
}