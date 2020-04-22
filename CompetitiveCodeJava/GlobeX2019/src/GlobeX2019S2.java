    import java.io.*;
    /**
     * GlobeX2019S2
     */
    public class GlobeX2019S2 {
        public static double twoLines(double m1, double m2, double b1, double b2){
            double x = (b2-b1)/(m1-m2);
            return x;
        }

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int N = Integer.parseInt(br.readLine());
            double[] NCo = new double[N+1];
            String[] temp = br.readLine().split(" ");
            for(int i = N; i>=0; i--){
                NCo[i] = Double.parseDouble(temp[Math.abs(i-N)]);
            } 
            int M = Integer.parseInt(br.readLine());
            double[] MCo = new double[M+1];
            String[] temp1 = br.readLine().split(" ");
            for(int i = M; i>=0; i--){
                MCo[i] = Double.parseDouble(temp1[Math.abs(i-M)]);
            }

            double m1;
            double m2;
            if(N == 0){
                m1 = 0;
            }
            else{
                m1 = NCo[1];
            }
            if(M == 0){
                m2 = 0;
            }
            else{
                m2 = MCo[1];
            }
            
            System.out.printf("%.8f", twoLines(m1,m2,NCo[0],MCo[0]));
            
            
        }
    }