import java.io.*;

/**
 * CCC11J4 - Boring Business
 */
public class CCC11J4 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[][] grid = new boolean[200][401];
        //Initialize grid[y][x]
        grid[0][200] = true; grid[1][200] = true; grid[2][200] = true;
        grid[2][201] = true; grid[2][202] = true; grid[2][203] = true;
        grid[3][203] = true; grid[4][203] = true; 
        grid[4][204] = true; grid[4][205] = true;
        grid[3][205] = true; grid[2][205] = true;
        grid[2][206] = true;
        for(int i = 2;i<7;i++){
            grid[i][207] = true;
        }
        for(int k = 0;k<9;k++){
            grid[6][207-k] = true;
        }
        grid[5][199] = true; grid[4][199] = true;
        
        //Subtract 200
        int currentX = 199;
        //Add one and negative
        int currentY = 4;
        while(true){
            String commands[] = br.readLine().split(" ");
            String direction = commands[0];
            if(direction.equals("q")){
                break;
            }
            else{
                int distance = Integer.parseInt(commands[1]);
                boolean dangerous = false;
                if(direction.equals("r")){
                    for(int g = 1;g<distance+1;g++){
                        currentX++;
                        if(grid[currentY][currentX]){
                            dangerous = true;
                        }
                        grid[currentY][currentX] = true;
                    }
                }
                if(direction.equals("l")){
                    for(int g = 1;g<distance+1;g++){
                        currentX--;
                        if(grid[currentY][currentX]){
                            dangerous = true;
                        }
                        grid[currentY][currentX] = true;
                    }
                }
                if(direction.equals("u")){
                    for(int g = 1;g<distance+1;g++){
                        currentY--;
                        if(grid[currentY][currentX]){
                            dangerous = true;
                        }
                        grid[currentY][currentX] = true;
                    }
                }
                if(direction.equals("d")){
                    for(int g = 1;g<distance+1;g++){
                        currentY++;
                        if(grid[currentY][currentX]){
                            dangerous = true;
                        }
                        grid[currentY][currentX] = true;
                    }
                }

                System.out.print(Integer.toString(currentX-200) + " " + Integer.toString(-(currentY+1)));
                if(dangerous){
                    System.out.print(" DANGER");
                    break;
                }
                else{
                    System.out.print(" safe");
                    System.out.println();
                }
            }
        }
    }
}