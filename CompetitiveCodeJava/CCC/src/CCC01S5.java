import java.io.*;
/**
 * CCC01S5
 */
public class CCC01S5 {
    static int m;
    static int n;
    static String[] a;
    static String[] b;
    static int index;
    static int[] combination;
    static boolean found = false;

    public static void getNext(int step, String A, String B){
        if(step>m-1){
            return;
        }
        for(int i = 0; i<n; i++){
            if(!found){
                String newA = A+a[i];
                String newB = B+b[i];
                
                if(newA.equals(newB)){
                    index = step+1;
                    combination[step] = i;
                    found = true;
                    
                    return;
                }
                int minLength = Math.min(newA.length(),newB.length());
                if(newA.substring(0,minLength).equals(newB.substring(0,minLength))){
                    combination[step] = i;
                    getNext(step+1,newA,newB);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        m = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());
        a = new String[n];
        b = new String[n];
        combination = new int[m+1];
        for(int i = 0; i<n; i++){
            a[i] = br.readLine();
        }
        for(int i = 0; i<n; i++){
            b[i] = br.readLine();
        }

        getNext(0,"","");
        if(found){
            System.out.println(index);
            for(int k = 0; k<index; k++){
                System.out.println(combination[k]+1);
            }
        }
        else{
            System.out.println("No solution.");
        }
        
    }
}