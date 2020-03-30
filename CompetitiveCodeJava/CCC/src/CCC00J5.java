import java.io.*;
import java.util.*;
/**
 * CCC00J5 - Surfing
 */
public class CCC00J5 {
    public static void getSites(String nextLine,ArrayList<ArrayList<String>> direct, int k){
        int index = 0;
        while(true){
            if(nextLine.indexOf("<A HREF=",index) == -1){
                break;
            }
            else{
                int startLink = nextLine.indexOf("<A HREF=",index) + 9;
                int endLink = nextLine.indexOf("\"",startLink+1);
                index = endLink+1;
                String website = nextLine.substring(startLink,endLink);
                direct.get(k).add(website);
            }
        }
    }

    public static boolean getLink(String sites[], int n, String first, String end, ArrayList<ArrayList<String>> direct){
        ArrayList<Integer> toCheck = new ArrayList<>();
        boolean[] visited = new boolean[n];
        toCheck.add(Arrays.asList(sites).indexOf(first));
 
        while(true){
            if(toCheck.size() == 0){
                return false;
            }
            else{
                if(sites[toCheck.get(0)].equals(end)){
                    return true;
                }
                for(String e: direct.get(toCheck.get(0))){
                    if(Arrays.asList(sites).indexOf(e)!=-1){
                        if(visited[Arrays.asList(sites).indexOf(e)] == false){ 
                            toCheck.add(Arrays.asList(sites).indexOf(e));
                        }
                    } 
                }
                visited[toCheck.get(0)] = true;
                toCheck.remove(0);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] sites = new String[n];
        ArrayList<ArrayList<String>> direct = new ArrayList<ArrayList<String>>(n);
        for(int k = 0;k<n;k++){
            direct.add(new ArrayList<>());
            sites[k] = br.readLine();
            while(true){
                String nextLine = br.readLine();
                if(nextLine.contains("</HTML>")){
                    break;
                }
                else if(nextLine.contains("<A HREF=")){
                    getSites(nextLine,direct,k);
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(String e: direct.get(i)){
                System.out.println("Link from " + sites[i] + " to " + e);
            }
        }
        while(true){
            String first = br.readLine();
            String second;
    
            if(first.equals("The End")){
                break;
            }
            else{
                second = br.readLine();
                boolean yes = getLink(sites,n,first,second,direct);
                if(yes == true){
                    System.out.println("Can surf from " + first + " to " + second + ".");
                }   
                else{
                    System.out.println("Can't surf from " + first + " to " + second + ".");
                }
            }
        }
    }
}