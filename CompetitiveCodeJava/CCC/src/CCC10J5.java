import java.io.*;
import java.util.*;

/**
 * CCC10J5 - Knight Hop
 */
public class CCC10J5 {
    static int endX;
    static int endY;
    static int endDistance;
    
    public static void move(Queue<int[]> toVisit, boolean grid[][], int[][] movement){

        int[] currentCoordinates = toVisit.poll();
        int currentX = currentCoordinates[0];
        int currentY = currentCoordinates[1];
        int distance = currentCoordinates[2];
        grid[currentY][currentX] = true;
        if(currentX == endX && currentY == endY){
            endDistance = distance;
            toVisit.clear();
            return;
        }

        for(int i = 0;i<8;i++){
            int newY = currentY +movement[i][1];
            int newX = currentX +movement[i][0];
            if(!(newY >8 || newX > 8 || newY <1 || newX < 1)){
                if(!grid[newY][newX]){
                    int add[] = {newX,newY,distance+1};
                    toVisit.add(add);
                }
            }  
        }   
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] first = br.readLine().split(" ");
        String[] second = br.readLine().split(" ");
        int knightX = Integer.parseInt(first[0]);
        int knightY = Integer.parseInt(first[1]);
        endX = Integer.parseInt(second[0]);
        endY = Integer.parseInt(second[1]);
        
        int[][] movement = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
        Queue<int[]> toVisit = new LinkedList<>();
        boolean grid[][] = new boolean[9][9];

        int[] temp = {knightX,knightY,0};
        toVisit.add(temp);
        while(!toVisit.isEmpty()){
            move(toVisit,grid,movement);
        }
        System.out.println(endDistance);
    }
}