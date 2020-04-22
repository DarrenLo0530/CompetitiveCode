/**
 * Boggled
 */
import java.io.*;
import java.util.*;

class Coord{
    int x, y;
    Coord(int x, int y){
        this.x = x;
        this.y = y;
    }
}
public class Boggled {
    static int[][] movement = {{1,1}, {-1,-1}, {1,-1}, {-1,1}, {0,1}, {1,0}, {-1,0}, {0,-1}};
    public static boolean findWord(char[][] board, int currIndex, String word, Coord curr, boolean[][] visited){
        boolean res = false;

        for(int i = 0; i<8; i++){
            int newX = curr.x + movement[i][0];
            int newY = curr.y + movement[i][1];
            if(newX >= 0 && newX < 4 && newY >=0 && newY < 4){
                if(word.charAt(currIndex) == board[newY][newX] && !visited[newY][newX]){
                    if(currIndex == word.length()-1){
                        return true;
                    }
                    visited[newY][newX] = true;
                    res = res || findWord(board, currIndex+1, word, new Coord(newX, newY), visited);
                    visited[newY][newX] = false;
                }
            }

            if(res){
                return res;
            }
        }

        return res;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i<5; i++){
            Set<String> used = new HashSet<>();
            int score = 0;
            int good = 0;
            int notFound = 0;
            int tooShort = 0;
            int repeated = 0;
            char currBoard[][] = new char[4][4];
            for(int k = 0; k<4; k++){
                String line = br.readLine();
                for(int e = 0; e<4; e++){
                    currBoard[k][e] = line.charAt(e);
                }
            }

            int N = Integer.parseInt(br.readLine());
            for(int f = 0; f<N; f++){
                boolean found = false;
                String currWord = br.readLine();
                if(currWord.length() <= 2){
                    tooShort++;
                } else if(used.contains(currWord)){
                    repeated++;
                } else {
                    for(int j = 0; j<4 && !found; j++){
                        for(int l = 0; l<4 && !found; l++){
                            if(currBoard[j][l] == currWord.charAt(0)){
                                boolean visited[][] = new boolean[4][4];
                                visited[j][l] = true;
                                found = found || findWord(currBoard, 1, currWord, new Coord(l,j), visited);
                                visited[j][l] = false;
                            }
                        }
                    }
                    if(!found){
                        notFound++;
                    } else {
                        good++;
                        if(currWord.length() == 3 || currWord.length() == 4){
                            score++;
                        } else if (currWord.length() == 5){
                            score += 2; 
                        } else if (currWord.length() == 6){
                            score += 3;
                        } else if (currWord.length() == 7){
                            score += 4;
                        } else if (currWord.length() > 7){
                            score += 11;
                        }
                    }
                }
                used.add(currWord);
            }
            System.out.printf("Your score: %d (%d good, %d not found, %d too short, %d repeated)%n", score, good, notFound, tooShort, repeated);
        }

    }
}