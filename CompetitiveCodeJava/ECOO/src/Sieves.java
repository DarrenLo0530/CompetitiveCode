/**
 * Sieves
 */
import java.util.*;

public class Sieves {

    public static void main(String[] args) {
        boolean[] comp = new boolean[10000000];
        Arrays.fill(comp, true);
        comp[2] = true;
        for(int i = 2; i<Math.sqrt(10000000)+1; i++){
            if(comp[i] == true){
                for(int k = 1; k*i < 10000000l; k++){
                    comp[k*i] = true;
                }
            }
        }
        if(comp[123021]){
            System.out.println("HI");
        }

    }
}