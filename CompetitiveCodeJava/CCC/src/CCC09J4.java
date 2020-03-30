import java.io.*;
import java.util.*;

/**
 * CCC09J4
 */
public class CCC09J4 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] words = {"WELCOME","TO","CCC","GOOD","LUCK","TODAY"};
        int[] wordsOnLine = new int[6];

        int w = Integer.parseInt(br.readLine());
        int lengthCounter = 0;
        int counter = 0;
        
        for(int i = 0;i<6;i++){
            int temp;
            if(lengthCounter == 0){
                temp = words[i].length()+lengthCounter;
            }
            else{
                temp = words[i].length()+lengthCounter+1;
            }
            if(temp>w){
                lengthCounter = 0;
                i-=1;
                counter+=1;
            }
            else{
                lengthCounter=temp;
                wordsOnLine[counter] +=1;
            }

        }
        int currWord = 0;
        for(int k:wordsOnLine){
            if(k==1){
                System.out.print(words[currWord]);
                for(int e = 0;e<w-words[currWord].length();e++){
                    System.out.print(".");
                }
                currWord+=1;
            }
            else if(k-1>0){
                int length = 0;
                for(int d = 0;d<k;d++){
                    length+=words[currWord+d].length();
                }
                int[] numSpaces = new int[k-1];
                int spaces = w-length-(int)Math.floor((w-length)/(k-1))*(k-1);
                Arrays.fill(numSpaces,(int)Math.floor((w-length)/(k-1)));
                for(int g = 0;g<spaces;g++){
                    numSpaces[g] +=1;
                }
                for(int f = 0;f<k;f++){
                    System.out.print(words[currWord+f]);
                    if(f<k-1){
                        for(int q = 0;q<numSpaces[f];q++){
                            System.out.print(".");
                        }
                    }
                }
                currWord+=k;                
            }
            if(k!=0){
                System.out.println();                
            }
        }
    }
}