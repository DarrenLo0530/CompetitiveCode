/**
 * CCC03S3
 */
import java.io.*;
import java.util.*;


public class CCC03S3 {
    static int N, R, C;
    static int[][] movement = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    static class Coordinate{
        int x;
        int y;
        Coordinate(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static Coordinate getNextPoint(char[][] room){
        for(int i = 0; i<R; i++){
            for(int k = 0; k<C; k++){
                if(room[i][k] == '.'){
                    return new Coordinate(k, i);
                }
            }
        }
        Coordinate noNode = new Coordinate(-1, -1);
        return noNode;
    }

    public static int getArea(char[][] room){
        Coordinate nextPoint = getNextPoint(room);
        if(nextPoint.x == -1){
            return -1;
        }
        
        int numNodes = 0;
        ArrayList<Coordinate> toCheck = new ArrayList<>();
        toCheck.add(nextPoint);

        while(!toCheck.isEmpty()){
            numNodes += 1;
            Coordinate checkPoint = toCheck.get(0);
            toCheck.remove(0);
            room[checkPoint.y][checkPoint.x] = 'I';

            for(int[] moves: movement){
                int newX = checkPoint.x + moves[0];
                int newY = checkPoint.y + moves[1];
                if(newX >= 0 && newX < C && newY >= 0 && newY < R){
                    if(room[newY][newX] != 'I'){
                        room[newY][newX] = 'I';
                        toCheck.add(new Coordinate(newX, newY));
                    }
                }
            }
        }
        return numNodes;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        R = Integer.parseInt(br.readLine());
        C = Integer.parseInt(br.readLine());
    
        char[][] floorPlan = new char[R][];
        for(int i = 0; i<R; i++){
            String row = br.readLine();
            char[] floorRow = new char[C];
            for(int k = 0; k<C; k++){
                floorRow[k] = row.charAt(k);
            }
            floorPlan[i] = floorRow;
        }
        
        ArrayList<Integer> floorSizes = new ArrayList<>();

        while(true){
            int floorArea = getArea(floorPlan);
            if(floorArea == -1){
                break;
            }
            else{
                floorSizes.add(floorArea);
            }
        }

        Collections.sort(floorSizes);
        Collections.reverse(floorSizes);

        int rooms = 0;
        while(floorSizes.size() > 0){
            int newN = N - floorSizes.get(0);
            if(newN >= 0){
                floorSizes.remove(0);
                N = newN;
                rooms += 1;
            }
            else{
                break;
            }
        }
        
        if(rooms == 1){
            System.out.println(Integer.toString(rooms) + " room, " + Integer.toString(N) + " square metre(s) left over");
        }
        else{
            System.out.println(Integer.toString(rooms) + " rooms, " + Integer.toString(N) + " square metre(s) left over");
        }
    }
}