/**
 * CCC05J5
 */
import java.io.*;
public class CCC05J5 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String word = br.readLine();
            if(word.equals("X")){
                break;
            }

            while((word.indexOf("BAS") != -1) || (word.indexOf("ANA") != -1)){
                word = word.replaceAll("ANA", "A");
                word = word.replaceAll("BAS", "A");
            }

            if(word.equals("A")){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        
    }
}