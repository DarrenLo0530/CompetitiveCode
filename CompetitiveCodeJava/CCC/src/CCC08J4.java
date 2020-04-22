import java.io.*;
import java.util.*;

/**
 * CCC08J4
 */
public class CCC08J4 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String line = br.readLine();
            if(line.equals("0")){
                break;
            }
            String[] split = line.split(" ");

            Stack<String> postFix = new Stack<>();
            for(int i = split.length-1;i>=0;i--){
                if(split[i].equals("+") || split[i].equals("-")){
                    String add = postFix.pop()+ postFix.pop() + split[i];
                    postFix.push(add);
                }
                else{
                    postFix.push(split[i]);
                }
                
            }
           for(String k: postFix.pop().split("")){
               System.out.print(k+" ");
           }
           System.out.println();
        }
        
    }
}