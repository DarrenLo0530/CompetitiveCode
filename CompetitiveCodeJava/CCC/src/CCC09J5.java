import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/**
 * CCC09J5
 */
public class CCC09J5 {
    public static void addFriend(ArrayList<HashSet<Integer>> graph, int x, int y){
        graph.get(x).add(y);
        graph.get(y).add(x);
    }

    public static void deleteFriend(ArrayList<HashSet<Integer>> graph, int x, int y){
        graph.get(x).remove(y);
        graph.get(y).remove(x);
    }

    public static int getNumFriends(ArrayList<HashSet<Integer>> graph, int x){
        return graph.get(x).size();
    }

    public static int getFriendFriends(ArrayList<HashSet<Integer>> graph, int x){
        Set<Integer> friendOfFriends = new HashSet<>();

        for(int i: graph.get(x)){
            for(int j: graph.get(i)){
                if(!graph.get(x).contains(j) && (j != x)){
                    friendOfFriends.add(j);
                }
            }
        }

        return friendOfFriends.size();
    }

    public static int getSeparation(ArrayList<HashSet<Integer>> graph, int x, int y){

        Queue<Integer> toVisit = new LinkedList<Integer>();
        boolean[] visited = new boolean[51];
        int separationCounter = 0;
        
        toVisit.add(x);
        visited[x] = true;        

        while(!toVisit.isEmpty()){
            Queue<Integer> nextToVisit = new LinkedList<Integer>();

            while(!toVisit.isEmpty()){
                int currNode = toVisit.poll();
                if(currNode == y){
                    return separationCounter;
                }
                for(int i: graph.get(currNode)){
                    if(!visited[i]){
                        nextToVisit.add(i);
                        visited[i] = true;
                    }
                }
            }
            
            separationCounter++;
            toVisit = nextToVisit;
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        ArrayList<HashSet<Integer>> graph = new ArrayList<HashSet<Integer>>();
        for(int i = 0; i<51; i++){
            graph.add(new HashSet<>());
        }

        addFriend(graph, 1, 6);
        addFriend(graph, 2, 6);
        addFriend(graph, 3, 6);
        addFriend(graph, 4, 6);
        addFriend(graph, 5, 6); 
        addFriend(graph, 3, 5);
        addFriend(graph, 3, 4);
        addFriend(graph, 4, 5);
        addFriend(graph, 6, 7);
        addFriend(graph, 7, 8);
        addFriend(graph, 8, 9);
        addFriend(graph, 9, 12);
        addFriend(graph, 9, 10);
        addFriend(graph, 10, 11);
        addFriend(graph, 11, 12);
        addFriend(graph, 3, 15);
        addFriend(graph, 12, 13);
        addFriend(graph, 13, 15);
        addFriend(graph, 13, 14);
        addFriend(graph, 16, 18);
        addFriend(graph, 16, 17);
        addFriend(graph, 17, 18);
        
        char opperation;
        int x, y, separation;
        do{
            opperation = sc.next().charAt(0);
            if(opperation == 'i'){
                x = sc.nextInt();
                y = sc.nextInt();
                addFriend(graph, x, y);
            } else if(opperation == 'd'){
                x = sc.nextInt();
                y = sc.nextInt();
                deleteFriend(graph, x, y);
            } else if(opperation == 'n'){
                x = sc.nextInt();
                System.out.println(getNumFriends(graph, x));
            } else if(opperation == 'f'){
                x = sc.nextInt();
                System.out.println(getFriendFriends(graph, x));
            } else if(opperation == 's'){
                x = sc.nextInt();
                y = sc.nextInt();
                separation = getSeparation(graph, x, y);
                if(separation == -1){
                    System.out.println("Not connected");
                } else {
                    System.out.println(separation);
                }
            }
            
        } while (opperation != 'q');
        sc.close();
    }
    
}