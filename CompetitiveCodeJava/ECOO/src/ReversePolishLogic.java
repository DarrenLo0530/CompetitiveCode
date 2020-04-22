
/**
 * ReversePolishLogic
 * INCOMPLETE
 */
import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class ReversePolishLogic {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<String> st = new Stack<>();
        Stack<BigDecimal> ans = new Stack<>();
        
        for(int f = 0; f<5; f++){
            String eq = br.readLine();
            char currOp;
            String display = "";
            BigDecimal displayNum = new BigDecimal(0);
            BigDecimal min = new BigDecimal(Integer.MIN_VALUE);
            String newVal;
            
            for(int i = 0; i<eq.length(); i++){
                if("0123456789.".indexOf(eq.charAt(i)) != -1){
                    display += eq.charAt(i);
                    displayNum = new BigDecimal(display);
                } else {
                    currOp = eq.charAt(i);
                    if(currOp == 'E'){
                        st.add(display);
                        ans.add(displayNum);
                    } else{
                        if(display.length() == 0){
                            display = st.pop();
                        }
                        if(displayNum.compareTo(min) == 0){
                            displayNum = ans.pop();
                        }

                        if (currOp == '+'){
                            newVal = st.pop() + " + " + display;
                            st.add(newVal);
                            ans.add(ans.pop().add(displayNum));
                        } else if (currOp == '-'){
                            newVal = st.pop() + " - " + display;
                            st.add(newVal);
                            ans.add(ans.pop().subtract(displayNum));

                        } else if (currOp == '*' || currOp == '/'){

                            String popped = st.pop();
                            if(popped.indexOf("-") != -1|| popped.indexOf("+") != -1){
                                popped = "(" + popped + ")";
                            }
                            if(display.indexOf("-") != -1 || display.indexOf("+") != -1){
                                display = "(" + display + ")";
                            } else if (currOp == '/' && (display.indexOf("*") != -1 || display.indexOf("/") != -1)){
                                display = "(" + display + ")";
                            }

                            if(currOp == '*'){
                                newVal = popped + " * " + display;
                                ans.add(ans.pop().multiply(displayNum));
                            } else {
                                newVal = popped + " / " + display;
                                ans.add(ans.pop().divide(displayNum));
                            }
                            st.add(newVal);
                            

                        } else if (currOp == '!'){
                            String popped = st.pop();
                            if(popped.indexOf("-") != -1    || popped.indexOf("+") != -1 || popped.indexOf("*") != -1 || popped.indexOf("/") != -1){
                                popped = "(" + popped + ")";
                            }
                            if(display.indexOf("-") != -1 || display.indexOf("+") != -1 || display.indexOf("*") != -1 || display.indexOf("/") != -1){
                                display = "(" + display + ")"; 
                            }
                            newVal = popped + " ! " + display;
                            st.add(newVal);
                            ans.add(ans.pop().pow(displayNum.intValue()));
                        }
                    }
                    display = "";
                    displayNum = min;
                }
            }   
            System.out.printf("%s = %s%n", st.pop(), ans.pop().stripTrailingZeros().toPlainString());  
        } 
    }
}