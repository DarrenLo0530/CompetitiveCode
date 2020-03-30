
/**
 * CCC05J5
 */
import java.io.*;
import java.util.*;
public class CCC04J5 {

    public static void findIntersection(int x, int width, boolean[][] grid){
        Set<Integer> inter = new HashSet<>();
        for(int i = 1; i < width+1; i++){
            if(grid[i][x] != grid[i-1][x]){
                inter.add(Math.abs(i-width-1));
            }
            if(grid[i][x+1] != grid[i-1][x+1]){
                inter.add(Math.abs(i-width-1));
            }
            if(grid[i][x] != grid[i][x+1]){
                inter.add(Math.abs(i-width-1));
            }
        }

        ArrayList<Integer> print = new ArrayList<>(inter);
        Collections.sort(print);
        for(int i: print){
            System.out.print(Integer.toString(i) + " ");
        }
    }

    public static void generateFractal(int width, boolean[][] grid){
        boolean[][] newFractalParts = new boolean[width+2][width+2];

        int upCounter = 0;
        int downCounter = 0;

        //Check row and create fractal upwards
        for(int i = 1; i < width+2; i++){ //row - y
            for(int k = 1; k < width+2; k++){ //column - x

                //Checks upward bulge
                if(grid[i][k] && !grid[i-1][k]){
                    upCounter++;
                }
                else if(upCounter > 0){
                    int fractSize = upCounter/3;
                    for(int e = i-fractSize; e<i; e++){
                        for(int f = k - 2*fractSize; f < k - fractSize; f++){
                            newFractalParts[e][f] = true;
                        }
                    }
                    upCounter = 0;
                }

                //Creates downwards bulge
                if(grid[i][k] && i+1 <= width && !grid[i+1][k]){
                    downCounter++;
                }
                else if(downCounter > 0){
                    int fractSize = downCounter/3;
                    for(int e = i+1; e<i+fractSize+1; e++){
                        for(int f = k - 2*fractSize; f < k - fractSize; f++){
                            newFractalParts[e][f] = true;
                        }
                    }
                    downCounter = 0;
                }
            }
        }

        int rightCounter = 0;
        int leftCounter = 0;

        for(int i = 1; i < width+1; i++){//Column - x
            for(int k = 1; k< width+1; k++){//Row - y
                //Creates leftrward bulge
                if(grid[k][i] && !grid[k][i-1]){
                    leftCounter++;
                }
                else if(leftCounter > 0){
                    int fractSize = leftCounter/3;
                    for(int e = k-fractSize*2; e < k - fractSize; e++){
                        for(int f = i - fractSize; f < i; f++){
                            newFractalParts[e][f] = true;
                        }
                    }
                    leftCounter = 0;
                }

                //Creates rightward bulge
                if(grid[k][i] && !grid[k][i+1]){
                    rightCounter++;
                }
                else if(rightCounter > 0){
                    int fractSize = rightCounter/3;
                    for(int e = k-fractSize*2; e < k - fractSize; e++){
                        for(int f = i+1; f < i+fractSize+1; f++){
                            newFractalParts[e][f] = true;
                        }
                    }
                    rightCounter = 0;
                }
            }
        }
        //Combine fractal and return
        for(int i = 1; i<width+1; i++){
            for(int j = 1; j<width+1; j++){
                if(newFractalParts[i][j]){
                    grid[i][j] = true;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] info = br.readLine().split(" "); 
        int lvl = Integer.parseInt(info[0]);
        int width = Integer.parseInt(info[1]);
        int x = Integer.parseInt(info[2]);

        boolean[][] grid = new boolean[width+2][width+2];//Add buffer on each side to avoid out of index error
        for(int i = 1; i<width+1; i++){
            grid[width][i] = true;
        }

        for(int i = 0; i < lvl; i++){
            generateFractal(width, grid);
        }

        findIntersection(x, width, grid);



    }
}