    /**
     * CCC05S3
     */
    import java.io.*;

    public class CCC05S3 {

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            long maxVal = Long.MIN_VALUE;
            long minVal = Long.MAX_VALUE;
            long maxRow = Long.MIN_VALUE;
            long minRow = Long.MAX_VALUE;
            long minCol = Long.MAX_VALUE;
            long maxCol = Long.MIN_VALUE;
            long currVal;

            long[][] prevMatrix = new long[1][1];
            prevMatrix[0][0] = 1;
            int N = Integer.parseInt(br.readLine());

            for(int i = 0; i<N; i++){
                String[] mInfo = br.readLine().split(" ");
                int r = Integer.parseInt(mInfo[0]);
                int c = Integer.parseInt(mInfo[1]);
                long[][] currMatrix = new long[r][c];
                
                //Gets curr matrix
                for(int j = 0; j<r; j++){
                    String[] rows = br.readLine().split(" ");
                    for(int k = 0; k<c; k++){
                        currMatrix[j][k] = Long.parseLong(rows[k]);
                    }
                }
                
                //Creates new matrix
                long[][] newMatrix = new long[r * prevMatrix.length][c * prevMatrix[0].length];
                for(int j = 0; j<prevMatrix.length; j++){ //Row of previousMatrix
                    for(int k = 0; k<prevMatrix[0].length; k++){ //Col previousMatrix
                        for(int l = 0; l<r; l++){ //Row of currMatrix
                            for(int m = 0; m<c; m++){ //Row of currMatrix
                                currVal = prevMatrix[j][k] * currMatrix[l][m];
                                newMatrix[j*r + l][k*c + m] = currVal;
                            }
                        }
                    }
                }

                prevMatrix = newMatrix;
            }

            for(int i = 0; i<prevMatrix.length; i++){//Row
                long rowSum = 0;
                for(int k = 0; k<prevMatrix[0].length; k++){//Column
                    rowSum += prevMatrix[i][k];          
                    maxVal = Math.max(prevMatrix[i][k], maxVal);
                    minVal = Math.min(prevMatrix[i][k], minVal); 
                }                
                minRow = Math.min(rowSum, minRow);
                maxRow = Math.max(rowSum, maxRow);
            }

            for(int i = 0; i<prevMatrix[0].length; i++){//Every column
                long colSum = 0;
                for(int k = 0; k<prevMatrix.length; k++){//Every row
                    colSum += prevMatrix[k][i];
                }
                minCol = Math.min(minCol, colSum);
                maxCol = Math.max(maxCol, colSum);
            }

            System.out.println(maxVal);
            System.out.println(minVal);
            System.out.println(maxRow);
            System.out.println(minRow);
            System.out.println(maxCol);
            System.out.println(minCol);            
        }
    }