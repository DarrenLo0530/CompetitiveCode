import java.io.*;

public class Itisatree {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int edges = 0;
        boolean wrong = false;
        for(int i = 0;i<4;i++){
            String[] temp = br.readLine().split(" ");
            boolean allZero = true;
            for(int k = 0;k<4;k++){
                if(Integer.parseInt(temp[k])==1){
                    edges+=1;
                    allZero = false;
                }
            }
            if(allZero){
                wrong = true; 
                break;
            }
        }
            
        if(edges/2==3){
            if(wrong){
                System.out.println("No");
            }
            else{
                System.out.println("Yes");
            }
        }
        else{
            System.out.println("No");
        }
    }
}