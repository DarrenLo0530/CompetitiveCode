/**
 * MockCCC220J2
 */
import java.io.*;


public class MockCCC220J2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String word = br.readLine();

        StringBuilder back = new StringBuilder();
        StringBuilder front = new StringBuilder();

        front.append(word.charAt(0));
        char frontLetter = word.charAt(0);

        for(int i = 1; i < N; i++){
            char curr = word.charAt(i);
            if(curr <= frontLetter){
                front.append(curr);
                frontLetter = curr;
            }
            else{
                back.append(curr);
            }
        }
        System.out.print(front.reverse());
        System.out.println(back);
    }
}