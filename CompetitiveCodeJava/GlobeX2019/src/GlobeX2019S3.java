import java.io.*;
/**
 * GlobeX2019S3
 */
public class GlobeX2019S3 {
    public static double calcSlope(double y, double x){
        return(y/x);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        double[] h = new double[N];
        double[] d = new double[N];
        String[] temp1 = br.readLine().split(" ");
        String[] temp2 = br.readLine().split(" ");
        for(int i = 0; i<N; i++){
            h[i] = Double.parseDouble(temp1[i]);
        }
        for(int i =0; i<N-1;i++){
            d[i] = Double.parseDouble(temp2[i]);
        }

        for(int i = 0; i<N;i++){
            int l = 0;
            int r = 0;
            if(i!=0){
                double currTallest = 0;
                double currSlope = -Double.MAX_VALUE;
                double currDist = 0;
                for(int j = i-1; j>=0; j--){
                    currDist += d[j];
                    if(h[j]>currTallest){               
                        double newSlope = calcSlope(h[j]-h[i],currDist);
                        if(newSlope>=currSlope){
                            currSlope = newSlope;
                            currTallest = h[j];
                        }
                    }
                }
                l = (int)currTallest;
            }
            else{
                l = -1;
            }

            if(i!=N-1){
                double currTallest = 0;
                double currSlope = -Double.MAX_VALUE;
                double currDist = 0;
                for(int j = i+1; j<N; j++){
                    currDist += d[j-1];
                    if(h[j]>currTallest){
                        double newSlope = calcSlope(h[j]-h[i],currDist);
                        if(newSlope>=currSlope){
                            currSlope = newSlope;
                            currTallest = h[j];
                        }
                    }
                }
                r = (int)currTallest;
            }
            else{
                r = -1;
            }

            System.out.println(Integer.toString(l) + " " + Integer.toString(r));
        }
    }
}