/**
 * CCC01S2 - Spiral
 */
import java.io.*;
import java.lang.Math;

public class CCC01S2 {

    public static void spiral(int x, int y, int matrix[][], int h,int k){
        int number = x;
        int currentX= (int) Math.floor((k-1)/2);
        int currentY= (int) Math.floor((h-1)/2);

        matrix[currentY][currentX] = number;
        number+=1;
        currentY+=1;
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
        int n = Integer.parseInt(br.readLine());
        for(int s = 0;s<n;s++){
            String[] temp = br.readLine().split(" ");
            int x = Integer.parseInt(temp[0]);
            int y = Integer.parseInt(temp[1]);
            int total = y-x+1;
            int h = 1;
            int k = 1;
            while(total>h*k){
                if(h<=k){
                    h++;
                }
                else{
                    k++;
                }
            }
            int[][] matrix = new int[h][k];
            spiral(x,y,matrix,h,k);
            
            int longest[] = new int[k];
            for(int i = 0;i<k;i++){
                int leng = 0;
                for(int e = 0;e<h;e++){
                    if(String.valueOf(matrix[e][i]).length() > leng){
                        leng = String.valueOf(matrix[e][i]).length();
                    }
                }
                longest[i] = leng;
            }

            for(int b = 0;b<h;b++){
                for(int c = 0;c<k;c++){
                    if(matrix[b][c]==0){
                        for(int w = 0;w<longest[c];w++){
                            System.out.print(" ");
                        }
                    }
                    else{
                        if(String.valueOf(matrix[b][c]).length() < longest[c]){
                            System.out.print(String.valueOf(" " + matrix[b][c]));
                        }
                        else{
                            System.out.print(String.valueOf(matrix[b][c]));
                        }
                    }
                    if(c!=k-1){
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }
            if(s!= n-1){
                System.out.println();
            }
        }
    }
}