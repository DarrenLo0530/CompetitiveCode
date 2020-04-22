import java.io.*;
import java.util.*;

/**
 * CCC00S5 - Sheep and Coyotes
 */
public class CCC00S5 {

    public static double distanceFormula(double x1,double y1, double x2, double y2){
        return Math.sqrt(Math.pow((x1-x2),2)+Math.pow((y1-y2),2));
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

        boolean[] eaten = new boolean[n];
        for(double g = 0.00;g<1000.00;g+=0.01){
            double shortestDist = Double.MAX_VALUE;
            ArrayList<Integer> smallest = new ArrayList<Integer>();
            for(int q = 0;q<n;q++){
                double distance = distanceFormula(g,0,xPos[q],yPos[q]);
                if(distance<shortestDist){
                    shortestDist = distance;
                    smallest.clear();
                    smallest.add(q);
                }
                else if(distance == shortestDist){
                    smallest.add(q);
                }
            }
            for(int b:smallest){
                eaten[b] = true;
            }
        }
            

        for(int f = 0;f<n;f++){
            if(eaten[f]){
                String xCoord = String.format("%.2f", xPos[f]);
                String yCoord = String.format("%.2f",yPos[f]);
                System.out.printf("The sheep at (" + xCoord + ", " + yCoord + ") might be eaten.");
                System.out.println();
            }
        }

    }
}