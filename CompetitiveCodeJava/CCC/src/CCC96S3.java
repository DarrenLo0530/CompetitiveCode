import java.io.*;

public class CCC96S3 {
    public static void nextBit(int length, int lengthMax, int onesLeft, String print){
        //base cases
        if(length!=lengthMax){
            if(onesLeft == 0){
                nextBit(length+1,lengthMax,onesLeft,print+"0");
            }
            else if(lengthMax-length<=onesLeft)
                nextBit(length+1,lengthMax,onesLeft-1,print+"1");
            else{
                nextBit(length+1,lengthMax,onesLeft-1,print+"1");
                nextBit(length+1,lengthMax,onesLeft,print+"0");
            }     
        }
        else if(length == lengthMax){
            System.out.println(print);
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0;i<T;i++){
            String temp[] = br.readLine().split(" ");
            int n = Integer.parseInt(temp[0]);
            int k = Integer.parseInt(temp[1]);
            System.out.println("The bit patterns are");
            nextBit(0,n,k,"");
        }
    }
}