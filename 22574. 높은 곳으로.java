import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int p = Integer.parseInt(input[1]);

            int maxFloor = 0;
            for (int i = 1; i <= n; i++) {
                maxFloor += i;
                if (maxFloor == p) {
                    // 폭탄이 설치된 층을 피하기 위해 그 층을 넘어간다
                    maxFloor--;
                }
            }

            System.out.println(maxFloor);
        }
    }
}
