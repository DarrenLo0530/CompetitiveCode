/**
 * MockCCC220J1
 */
import java.io.*;
import java.util.*;

public class MockCCC220J1 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] tempNums = br.readLine().split(" ");
        int[] nums = new int[N];

        for(int i = 0; i < N; i++){
            nums[i] = Integer.parseInt(tempNums[i]);
        }

        Arrays.sort(nums);

        for(int i: nums){
            System.out.printf("%d ", i);
        }
    }
}