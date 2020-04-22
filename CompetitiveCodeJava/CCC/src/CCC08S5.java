    import java.io.*;
    /**
     * CCC08S5
     */
    public class CCC08S5 {
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int N = Integer.parseInt(br.readLine());

            for(int i = 0; i < N; i++){
                int[][] combinations = {{2,1,0,2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
                String[] tempStart = br.readLine().split(" ");
                int[] start = new int[4];
                for(int j = 0; j < 4; j++){
                    start[j] = Integer.parseInt(tempStart[j]);
                }
                
                //* ABCD
                boolean[][][][] winState = new boolean[start[0] + 1][start[1] + 1][start[2] + 1][start[3] + 1];

                for(int a = 0; a < start[0] + 1; a++){
                    for(int b = 0; b < start[1] + 1; b++){
                        for(int c = 0; c < start[2] + 1; c++){
                            for(int d = 0; d < start[3] + 1; d++){
                                boolean perfectWin = false;

                                for(int[] combo: combinations){
                                    int newA = a - combo[0];
                                    int newB = b - combo[1];
                                    int newC = c - combo[2];
                                    int newD = d - combo[3];
                                
                                    if(!(newA < 0 || newB < 0 || newC < 0 || newD < 0)){
                                        if(!winState[newA][newB][newC][newD]){
                                            perfectWin = true;
                                        }
                                    }                   
                                }

                                winState[a][b][c][d] = perfectWin;
            
                            }
                        }
                    }
                }
                if(winState[start[0]][start[1]][start[2]][start[3]]){
                    System.out.println("Patrick");
                }
                else{
                    System.out.println("Roland");
                }
            }
        }
    }