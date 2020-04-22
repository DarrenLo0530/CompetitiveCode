/**
 * CCC06S3
 */
import java.io.*;

public class CCC06S3 {
    static class Coordinate{
        double x, y;
        Coordinate(double x, double y){
            this.x = x;
            this.y = y;
        }
    }

    public static double calculateSlope(Coordinate a, Coordinate b){
        return (a.y-b.y)/(a.x-b.x);
    }
    public static double calculateYInt(double m, Coordinate a){
        //If slope is vertical, then return the x value of the vertical line
        if(Double.isInfinite(m)){
            return a.x;
        }
        //Find slope normally
        double b = a.y - m*a.x;
        return b;
    }
    public static Coordinate calculateIntersection(double m1, double b1, double m2, double b2){
        //Finds the intersection between a vertical line and one that is not
        if(Double.isInfinite(m2) && !Double.isInfinite(m1)){
            double y = m1*b2+b1;
            return new Coordinate(b2, y);
        }
        else if(Double.isInfinite(m1) && !Double.isInfinite(m2)){
            double y = m2*b1+b2;
            return new Coordinate(b1, y);
        }
        //Otherwise just find intersection normally
        else{
            double x = (b1-b2)/(m2-m1);
            double y = m1*x+b1;
            return new Coordinate(x, y);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] peopleInfo = br.readLine().split(" ");
        Coordinate p1 = new Coordinate(Integer.parseInt(peopleInfo[0]), Integer.parseInt(peopleInfo[1]));
        Coordinate p2 = new Coordinate(Integer.parseInt(peopleInfo[2]), Integer.parseInt(peopleInfo[3]));

        double minX = Math.min(p1.x ,p2.x);
        double maxX = Math.max(p1.x ,p2.x);
        double minY = Math.min(p1.y, p2.y);
        double maxY = Math.max(p1.y ,p2.y);

        double m = calculateSlope(p1, p2);
        double b = calculateYInt(m, p1);
        int blockedCounter = 0;

        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i<N; i++){
            String[] bInfo = br.readLine().split(" ");
            int numPoints = Integer.parseInt(bInfo[0]);
            Coordinate[] points = new Coordinate[numPoints+1];

            for(int a = 0; a<numPoints; a++){
                points[a] = new Coordinate(Integer.parseInt(bInfo[a*2+1]), Integer.parseInt(bInfo[a*2+2]));
            }
            
            points[numPoints] = points[0];

            for(int a = 0; a<numPoints; a++){
                double mBuilding = calculateSlope(points[a], points[a+1]);
                double bBuilding = calculateYInt(mBuilding, points[a]);
                Coordinate intersection = calculateIntersection(m, b, mBuilding, bBuilding);
                
                double minBX = Math.min(points[a].x, points[a+1].x);
                double maxBX = Math.max(points[a].x, points[a+1].x);
                double minBY = Math.min(points[a].y, points[a+1].y);
                double maxBY = Math.max(points[a].y, points[a+1].y);
                
                //Two vertical lines are parallel
                //If two vertical lines overlap, x coordinate of intersection is NaN and not infinite since it is 0/0 
                if(Double.isInfinite(intersection.x)){
                    continue;
                }
                //Two lines are overlapping
                if(m == mBuilding && b == bBuilding){
                    if((minBX >= minX && minBX <= maxX) || minX >= minBX && minX <= maxBX){
                        blockedCounter++;
                        break;
                    }                
                }
                
                //If two lines are not vertical, just check where intersection is and if it is within the two line segments
                else if(intersection.x >= minX && intersection.x <= maxX && intersection.y >= minY && intersection.y <= maxY
                    && intersection.x >= minBX && intersection.x <= maxBX && intersection.y >= minBY && intersection.y <= maxBY){
                    blockedCounter++;
                    break;
                } 
            }
        }

        System.out.println(blockedCounter);
    }
}