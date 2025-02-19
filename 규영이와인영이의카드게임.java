import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 규영이와인영이의카드게임 {
    static int[] inyoungCards = new int[9]; // 인영이의 카드
    static int[] output = new int[9]; // 순열 저장
    static boolean[] visited = new boolean[9]; // 방문 체크
    static int win, lose;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            boolean[] isUsed = new boolean[19]; // 1~18 사용 여부 체크
            int[] guyoung = new int[9];
            String[] input = br.readLine().split(" ");

            for (int i = 0; i < 9; i++) {
                guyoung[i] = Integer.parseInt(input[i]);
                isUsed[guyoung[i]] = true;
            }
            int idx = 0;
            for (int i = 1; i <= 18; i++) {
                if (!isUsed[i]) {
                    inyoungCards[idx++] = i;
                }
            }
            win = 0;
            lose = 0;
            Arrays.fill(visited, false);
            permutation(guyoung, 0);
            System.out.println("#" + t + " " + win + " " + lose);
        }
    }

    static void permutation(int[] guyoung, int depth) {
        if (depth == 9) {
            int guyoungSum = 0, inyoungSum = 0;

            for (int i = 0; i < 9; i++) {
                int sum = guyoung[i] + output[i];
                if (guyoung[i] > output[i]) {
                    guyoungSum += sum;
                } else {
                    inyoungSum += sum;
                }
            }

            if (guyoungSum > inyoungSum) win++;
            else if (guyoungSum < inyoungSum) lose++;

            return;
        }

        for (int i = 0; i < 9; i++) {
            if (!visited[i]) {
                visited[i] = true;
                output[depth] = inyoungCards[i];
                permutation(guyoung, depth + 1);
                visited[i] = false;
            }
        }
    }
}
