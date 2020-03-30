import java.io.*;

/**
 * CCC00S5Improved
 */
public class CCC00S5Improved {
    public static double distance(double x1, double y1, double x2, double y2){
        return Math.sqrt(Math.pow(x1-x2,2) + Math.pow(y1-y2,2));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double[] xPos = new double[n];
        double[] yPos = new double[n];

        for(int i = 0;i<n;i++){
            xPos[i] = Double.parseDouble(br.readLine());
            yPos[i] = Double.parseDouble(br.readLine());
        }

        boolean[] impossible = new boolean[n];

        for(int k =0;k<n;k++){
            double maxLeft = 0;
            double minRight = 1000;
            if(!impossible[k]){
                for(int e =0;e<n;e++){
                    if(e!=k && !impossible[e]){
                        double midX = (xPos[k] + xPos[e])/2;
                        double midY = (yPos[k] + yPos[e])/2;
                        if(xPos[k]-xPos[e] == 0){
                            if(yPos[k] > yPos[e]){
                                impossible[k] = true;
                            }
                            else{
                                impossible[e] = true;
                            }
                        }
        
                        else{
                            double perpendicularSlope = -1/ ((yPos[k]-yPos[e])/(xPos[k]-xPos[e]));
                            double xInt = -midY/perpendicularSlope + midX;
                            if(xPos[k]>xPos[e]){
                                maxLeft = Math.max(maxLeft,xInt);
                            }
                            else if(xPos[k]<xPos[e]){
                                minRight = Math.min(minRight,xInt);
                            }
                        }
                    }
                }  
            }
            if(maxLeft>minRight){
                impossible[k] = true;
            }
        }
            
        for(int f = 0;f<n;f++){
            if(!impossible[f]){
                String xCoord = String.format("%.2f", xPos[f]);
                String yCoord = String.format("%.2f",yPos[f]);
                System.out.printf("The sheep at (" + xCoord + ", " + yCoord + ") might be eaten.");
                System.out.println();
            }
        }
    }
}