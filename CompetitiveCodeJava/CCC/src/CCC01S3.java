import java.io.*;
import java.util.*;
/**
 * CCC01S3
 */
public class CCC01S3 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> connections = new ArrayList<>();
        HashMap<Character,ArrayList<Character>> adj = new HashMap<>();

        while(true){
            String input = br.readLine();
            if(input.equals("**")){
                break;
            }
            else{
                connections.add(input);
                if(!adj.containsKey(input.charAt(0))){
                    adj.put(input.charAt(0),new ArrayList<>());
                    adj.get(input.charAt(0)).add(input.charAt(1));
                }
                else{
                    adj.get(input.charAt(0)).add(input.charAt(1));
                }
                if(!adj.containsKey(input.charAt(1))){
                    adj.put(input.charAt(1),new ArrayList<>());
                    adj.get(input.charAt(1)).add(input.charAt(0));
                }
                else{
                    adj.get(input.charAt(1)).add(input.charAt(0));
                }
            }
        }

        int numRoads = 0;
        for(int i = 0; i < connections.size(); i++){
            String toBomb = connections.get(i);
            ArrayList<Character> visited = new ArrayList<>();
            Queue<Character> toVisit = new LinkedList<>();

            toVisit.add('A');
            while(!toVisit.isEmpty()){
                Character current = toVisit.poll();
                visited.add(current);
                if(adj.containsKey(current)){
                    for(Character e:adj.get(current)){
                        if(!(current.equals(toBomb.charAt(0)) && e.equals(toBomb.charAt(1))) && !(current.equals(toBomb.charAt(1)) && e.equals(toBomb.charAt(0)))){
                            if(!visited.contains(e)){
                                toVisit.add(e);
                            }
                        }
                    }
                }
            }
            if(!visited.contains('B')){
                numRoads++;
                System.out.println(connections.get(i));
            }
        }
        System.out.println("There are " + Integer.toString(numRoads) + " disconnecting roads.");
        

    }
}