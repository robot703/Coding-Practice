import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 달팽이숫자_1954 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());


        int[][] arr;

        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        for (int t = 1; t <= T; t++) {
            int x = 0, y = 0, d = 0;
            int num = 1;
            int N = Integer.parseInt(br.readLine());
             arr = new int[N][N];
            while (num <= N * N) {
                arr[x][y] = num++;
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[nx][ny] != 0) {
                    d = (d + 1) % 4;
                    nx = x + dx[d];
                    ny = y + dy[d];
                }
                x = nx;
                y = ny;
            }

            System.out.println("#" + t);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(arr[i][j] + " ");
                }
                System.out.println();

            }
        }
    }
}

