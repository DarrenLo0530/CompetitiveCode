import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * CCC14J3
 */
public class CCC14J3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0;i<T;i++){
            int counter = 1;
            Stack<Integer> mountain  = new Stack<>();
            Stack<Integer> branch = new Stack<>();
            int N = Integer.parseInt(br.readLine());
            for(int k = 0;k<N;k++){
                int car = Integer.parseInt(br.readLine());
                mountain.push(car);
            }
            boolean possible = true;
            while(possible){
                int mountainNext = 0;
                int branchNext = 0;

                if (!mountain.empty()){
                    mountainNext = mountain.peek();
                }
                if (!branch.empty()){
                    branchNext = branch.peek();
                }

                if(mountain.empty() && branchNext!=counter){
                    possible = false;
                }
                if (branchNext == counter){
                    branch.pop();
                    counter+=1;
                }
                else if (mountainNext == counter){
                    mountain.pop();
                    counter+=1;
                }
                else{
                    if(!mountain.empty()){
                        branch.add(mountain.pop());
                    }
                }
                if(mountain.empty() && branch.empty()){
                    break;
                }    
            }
        if (possible){
            System.out.println("Y");
        }
        else{
            System.out.println("N");
        }
    }
}
}   