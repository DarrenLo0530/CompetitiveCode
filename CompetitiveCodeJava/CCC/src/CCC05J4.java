import java.io.*;

/**
 * CCC05J4 - Cross Spiral
 */
public class CCC05J4 {
    public static boolean up(int currentX,int currentY,int[][] cross){
        if(currentY-1>0){
            if(cross[currentY-1][currentX]!=1){
                return true;
            }
        }
        return false;
    }
    public static boolean down(int currentX,int currentY, int[][] cross,int h){
        if(currentY+1<h){
            if(cross[currentY+1][currentX]!=1){
                return true;
            }
        }
        return false;
    }
    public static boolean right(int currentX,int currentY, int[][] cross,int w){
        if(currentX+1<w){
            if(cross[currentY][currentX+1] != 1){
                return true;
            }
        }
        return false;
    }

    public static boolean left(int currentX,int currentY, int[][] cross){
        if(currentX-1 >=0){
            if(cross[currentY][currentX-1]!= 1){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int w = Integer.parseInt(br.readLine()), h = Integer.parseInt(br.readLine());
        int x = Integer.parseInt(br.readLine()), y = Integer.parseInt(br.readLine());
        int t = Integer.parseInt(br.readLine());

        int[][] cross = new int[h][w];
        for(int i = 0;i<y;i++){
            for(int j = 0;j<x;j++){
                cross[i][j] = 1;
                cross[i][w-1-j] = 1;
                cross[h-i-1][j] = 1;
                cross[h-i-1][w-j-1] = 1;
            }
        }

        int currentX = x;
        int currentY = 0;
        int counter = 0;
        int quadrant = 0;

        while(counter<t){
            cross[currentY][currentX]  = 1;
            if(currentX <= Math.ceil(w/2.0)-1 && currentY<= Math.floor(h/2.0)-1){
                quadrant = 4;
            }
            else if(currentX > Math.ceil(w/2.0)-1 && currentY<=Math.ceil(h/2.0)-1){
                quadrant = 1;
            }
            else if(currentX > Math.floor(w/2.0)-1 && currentY > Math.ceil(h/2.0)-1){
                quadrant = 2;
            }
            else if(currentX<=Math.floor(w/2.0)-1 && currentY >Math.floor(h/2.0)-1){
                quadrant = 3;
            }

            if(quadrant == 4){
                if(up(currentX,currentY,cross)){
                    currentY-=1;
                }
                else if(right(currentX,currentY,cross,w)){
                    currentX+=1;
                }
                else if(down(currentX,currentY,cross,h)){
                    currentY+=1;
                }

            }
            if(quadrant == 3){
                if(left(currentX,currentY,cross)){
                    currentX-=1;
                }
                else if(up(currentX,currentY,cross)){
                    currentY-=1;
                }
            }
            if(quadrant == 2){
                if(down(currentX,currentY,cross,h)){
                    currentY+=1;
                }
                else if(left(currentX,currentY,cross)){
                    currentX-=1;
                }
            }
            if(quadrant == 1){
                if(right(currentX,currentY,cross,w)){
                    currentX+=1;
                }
                else if(down(currentX,currentY,cross,h)){
                    currentY+=1;
                }
            }
            counter+=1;
        }
        
        System.out.println(currentX+1);
        System.out.println(currentY+1);        
    }
}