/**
 * CCC01S2 - Spiral
 */
import java.io.*;


public class CCC01S2bad {

    public static void spiral(int number, int y, int matrix[][]){
        number+=1;
        int currentX=5;
        int currentY=6;
        int orientation = 0;
        while(number<=y){
            if(orientation == 0){//checks upwards moving right
                while(matrix[currentY-1][currentX] != 0){
                    matrix[currentY][currentX] = number;
                    number+=1;
                    currentX+=1;
                    if(number > y){
                        return;
                    }
                }
                orientation = 1;
            }
            else if(orientation ==1){//checks left moving upwards
                while(matrix[currentY][currentX-1] !=0){
                    matrix[currentY][currentX] = number;
                    number+=1;
                    currentY -=1;
                    if(number > y){
                        return;
                    }
                }
                orientation = 2;
            }
            else if(orientation == 2){//checks downwards moving left
                while(matrix[currentY+1][currentX]!=0){
                    matrix[currentY][currentX] = number;
                    number+=1;
                    currentX-=1;

                    if(number > y){
                        return;
                    }
                }
                orientation = 3;
            }
            else if(orientation == 3){
                while(matrix[currentY][currentX+1]!=0){
                    matrix[currentY][currentX]= number;
                    number+=1;
                    currentY+=1;
                    if(number > y){
                        return;
                    }
                }
                orientation = 0;
            }
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine());
        int y = Integer.parseInt(br.readLine());
        int[][] matrix = new int[11][11];
        matrix[5][5] = x;
        spiral(x,y,matrix);
        
        int longest[] = new int[11];
        boolean allZeroRows[] = new boolean[11];
        boolean allZeroColumns[] = new boolean[11];

        for(int i = 0;i<11;i++){
            int leng = 0;
            boolean allZeroRow = true;
            boolean allZeroColumn = true;
            for(int e = 0;e<11;e++){
                if(String.valueOf(matrix[e][i]).length() > leng){
                    leng = String.valueOf(matrix[e][i]).length();
                }
                if(matrix[i][e] >0 ){
                    allZeroRow = false;
                }
                if(matrix[e][i]>0){
                    allZeroColumn = false;
                }
            }
            allZeroRows[i] = allZeroRow;
            allZeroColumns[i] = allZeroColumn;
            longest[i] = leng;
        }


        for(int b = 0;b<11;b++){
            if(!allZeroRows[b]){
                String print = "";
                for(int e = 0;e<11;e++){
                    if(!allZeroColumns[e] && matrix[b][e]!=0){
                        if(String.valueOf(matrix[b][e]).length() < longest[e]){
                            print+= String.valueOf(matrix[b][e]) + " ";
                        }
                        else{
                            print+= String.valueOf(matrix[b][e]);
                        }
                    }
                    else if(!allZeroColumns[e]){
                        for(int q = 0;q<longest[e];q++){
                            print+= " ";
                        }
                    }
                    if(e<10 && !allZeroColumns[e]){
                        if(!allZeroColumns[e+1]){
                            print+=" ";
                        }
                    }
                }
                String regex = "\\s+$";

                System.out.println(print.replaceAll(regex,""));
            }
        }
    }
}