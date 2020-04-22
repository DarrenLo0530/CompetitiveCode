
/**
 * BinaryIndexTreeTest
 */
import java.io.*;

public class BinaryIndexTreeTest {
    public static void update(int index, int val, long[] BIT){
        int n = BIT.length;
        while(index < n) {
            BIT[index] += ((long) val);
            index = index + (index & -index);
        }
    }

    public static long getSum(int e, long[] BITSum){
        long sum = 0;
        while(e > 0){
            sum += BITSum[e];
            e = e - (e & -e);
        }
        return sum;
    }

    public static long getRangeSum(int s, int e, long [] BITSum){
        return getSum(e, BITSum) - getSum(s, BITSum);
    }

    public static void constructBIT(int size, int[] arr, long[] BIT){
        for(int i = 1; i<size; i++){
            update(i, arr[i-1], BIT);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] NM = br.readLine().split(" ");
        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);
        int[] arr = new int[N];
        int[] freq = new int[100001];
        long[] BITSum = new long[N+1];
        long[] BITFreq = new long[100001];

        String[] arrIn = br.readLine().split(" ");
        for(int i = 0; i<N; i++){
            arr[i] = Integer.parseInt(arrIn[i]);
            freq[Integer.parseInt(arrIn[i]) - 1]++;
        }

        constructBIT(N+1, arr, BITSum);
        constructBIT(100001, freq, BITFreq);        

        for(int i = 0; i<M; i++){
            String[] command = br.readLine().split(" ");
            if(command[0].equals("C")){
                //Updates BITSum
                update(Integer.parseInt(command[1]), Integer.parseInt(command[2]) - arr[Integer.parseInt(command[1]) - 1], BITSum);
                //Updates frequency counter
                update(arr[Integer.parseInt(command[1]) - 1], -1, BITFreq);
                update(Integer.parseInt(command[2]), 1, BITFreq);
            }
            else if(command[0].equals("S")){
                int first = Integer.parseInt(command[1]);
                int second = Integer.parseInt(command[2]);
                System.out.println(getRangeSum(Math.min(first, second) - 1, Math.max(first, second), BITSum));
            }
            else{
                System.out.println(getSum(Integer.parseInt(command[1]), BITFreq));
            }
        }      
    }
}   