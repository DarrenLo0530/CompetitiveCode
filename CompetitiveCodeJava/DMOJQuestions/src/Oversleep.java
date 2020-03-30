    import java.io.*;
    import java.util.*;

    /**
     * Oversleep
     */
    public class Oversleep {
        static int startX;
        static int startY;
        static int endX;
        static int endY;
        static int n;
        static int m;
        static int[][] movement = {{1,0},{0,1},{-1,0},{0,-1}};

        public static void move(String[][] grid, boolean[][] visited, ArrayList<int[]> toCheck, int[][] dist){
            int[] next = toCheck.get(0);
            toCheck.remove(0);
            int x = next[0];
            int y = next[1];
            int distance = dist[y][x];

            visited[y][x] = true;

            for(int i = 0;i<4;i++){
                int newX = x+movement[i][0];
                int newY = y+movement[i][1];
                if(!(newX<0 || newX>m-1||newY<0||newY>n-1) && !visited[newY][newX] && !grid[newY][newX].equals("X")){
                    int[] tempAdd = {newX,newY};
                    if(!toCheck.contains(tempAdd)){
                        toCheck.add(tempAdd);
                        dist[newY][newX] = distance+1;
                    }
                }
                    
            }
        }

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] first = br.readLine().split(" ");
            n = Integer.parseInt(first[0]);
            m = Integer.parseInt(first[1]);
            ArrayList<int[]> toCheck = new ArrayList<>();
            String[][] grid = new String[n][m];
            boolean[][] visited = new boolean[n][m];
            int[][] dist = new int[n][m];
        
            for(int i = 0;i<n;i++){
                String line = br.readLine();
                for(int k = 0;k<m;k++){
                    if(String.valueOf(line.charAt(k)).equals("s")){
                        int add[] = {k,i};
                        toCheck.add(add);
                    }
                    else if(String.valueOf(line.charAt(k)).equals("e")){
                        endX = k;
                        endY = i;
                    }
                    grid[i][k] = String.valueOf(line.charAt(k));
                }
            }
            while(!toCheck.isEmpty()){
                move(grid,visited,toCheck,dist);
            }
            System.out.println(dist[endY][endX]-1);
                
        }
    }