import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class 수열정렬_1015 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> sortarr = new ArrayList<>(Collections.nCopies(N, 0));
        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(input[i]));
        }

        ArrayList<Integer> originalArr = new ArrayList<>(arr);

        for (int i = 0; i < N; i++) {
            int min = Collections.min(arr);
            int minIndex = arr.indexOf(min);
            sortarr.set(minIndex, i);
            arr.set(minIndex, Integer.MAX_VALUE);  // 최소값을 다시 선택되지 않도록 변경
        }

        for(Integer a : sortarr)
        System.out.print(a+" ");
    }
}
