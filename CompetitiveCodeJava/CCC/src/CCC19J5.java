import java.io.*;
import java.util.*; 

/**
 * CCC19J5
 */
public class CCC19J5 {
    static String desiredPattern;
    static Queue<String> outputPattern;
    static Map<String,String> patterns;
    static int stop;
    static Map<String,ArrayList<ArrayList<String>>> checked;
    int startStep;

    CCC19J5(String a, int b, Map<String,String> c){
        desiredPattern = a;
        outputPattern = new LinkedList<>();
        patterns = c;
        stop = b;
        checked =  new HashMap<String,ArrayList<ArrayList<String>>>();
        startStep = 0;
    }

    
    public void patternReplace(String inPattern){
        startStep += 1; 
        
        //Breaks out of method if the pattern at the correct step was found
    
        
        for(String patternUsed: patterns.values()){
        
            int index = 0;
            int end = 0;
            int patternUsedLength = patternUsed.length();
            while(index>=0){                
                
                index = inPattern.indexOf(patternUsed,end);
                end = index+1;
                String patternOut = inPattern.substring(0,index) + patternUsed + inPattern.substring(index+patternUsedLength,-1);
                
                if(patternOut.equals(desiredPattern)&& startStep == stop){
                    System.out.println(inPattern);
                    return;
                }

                if(!checked.containsKey(patternOut)){
                    ArrayList<String> arrivalStep = new ArrayList<>();
                    ArrayList<String> rule = new ArrayList<>();
                    ArrayList<String> origin = new ArrayList<>();
                    ArrayList<String> outPattern = new ArrayList<>();

                    ArrayList<ArrayList<String>> patternData = new ArrayList<>();
                    
                    arrivalStep.add(Integer.toString(startStep));
                    rule.add(patternUsed);
                    origin.add(inPattern);

                    patternData.add(arrivalStep);
                    patternData.add(rule);
                    patternData.add(origin);
                    patternData.add(outPattern);

                }
                else{
                    checked.get(patternOut).get(1).add(Integer.toString(startStep));
                    checked.get(patternOut).get(2).add(patternUsed);
                    checked.get(patternOut).get(3).add(inPattern);
                }
            }
        }
        String nextPattern = outputPattern.remove();
        patternReplace(nextPattern);
    }
        
        

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<String,String> patterns = new HashMap<>();

        for(int i = 0;i<3;i++){
            String pattern = br.readLine();
            String[] patternSplit = pattern.split(" ");
            patterns.put(patternSplit[0],patternSplit[1]); //Puts pattern in to a hashmap

        }

        String stuff = br.readLine();
        String[] splitted = stuff.split(" ");
        System.out.println(stuff);
        int stepsRequired  = Integer.parseInt(splitted[0]);
        String initialPattern  = splitted[1];
        String finalPattern = splitted[2];
        System.out.println("REEEE");

        CCC19J5 c = new CCC19J5(finalPattern,stepsRequired,patterns);
        c.patternReplace(initialPattern);
        
        for(String f:checked.keySet()){
            System.out.println(f);
        }
    }
}