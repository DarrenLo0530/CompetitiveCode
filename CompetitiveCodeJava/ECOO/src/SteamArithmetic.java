/**
 * SteamArithmetic
 */

import java.io.*;
import java.util.*;

public class SteamArithmetic {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int num1, num2;
        for(int k = 0; k<10; k++){
            String in = br.readLine();
            Stack<Integer> ans = new Stack<>();
            for(int i = in.length()-1; i>=0; i--){
                if("0123456789".indexOf(in.charAt(i)) != -1){
                    ans.add(Character.getNumericValue(in.charAt(i)));
                }
                else if("+-qr*".indexOf(in.charAt(i)) != -1){
                    num1 = ans.pop();
                    num2 = ans.pop();
                    if(in.charAt(i) == '+'){
                        ans.add(num1+num2);
                    } else if (in.charAt(i) == '-'){
                        ans.add(num1-num2);
                    } else if (in.charAt(i) == '*'){
                        ans.add(num1*num2);
                    } else if (in.charAt(i) == 'q'){
                        ans.add(num1/num2);
                    } else {
                        ans.add(num1%num2);
                    }
                }
            }

            System.out.println(ans.pop());  
        } 
    }

    
}