import java.io.*;


/**
 * CCC11J5 - Unfriend
 */
public class CCC11J5 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int totalPossibilities = 0;
        int[] dependency = new int[N+1];
        for(int i = 1;i<N;i++){
            int invitee = Integer.parseInt(br.readLine());
            if(invitee!=N){
                dependency[i] = invitee;
            }
        }
        for(int j = 0;j<Math.pow(2,N-1);j++){
            String binary = Integer.toBinaryString(j);
            for(int x = binary.length();x<N-1;x++){
                binary = "0" + binary;
            }
            boolean possibleCombo = true;
            for(int e = 1;e<N;e++){
                if(dependency[e]!=0){
                    if(String.valueOf(binary.charAt(e-1)).equals("0") && String.valueOf(binary.charAt(dependency[e]-1)).equals("1")){
                        possibleCombo = false;
                    }
                }
            }
            if(possibleCombo){
                totalPossibilities+=1;
            }
        }
        System.out.println(totalPossibilities);
    }
}