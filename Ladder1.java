import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Ladder1 {

    static int[][] arr = new int[100][100];
    static boolean[][] visited = new boolean[100][100];
    static int x = 0, y = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int t = 0; t < 10; t++) {
            for (int i = 0; i < 100; i++) {
                Arrays.fill(visited[i], false);
            }

            int T = Integer.parseInt(br.readLine());
            for (int i = 0; i < 100; i++) {
                String[] input = br.readLine().split(" ");
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = Integer.parseInt(input[j]);
                    if (arr[i][j] == 2) {
                        x = i;
                        y = j;
                    }
                }
            }
            visited[x][y] = true;

            while (x != 0) {
                if (y - 1 >= 0 && arr[x][y - 1] == 1 && !visited[x][y - 1]) {
                    y--;
                } else if (y + 1 < 100 && arr[x][y + 1] == 1 && !visited[x][y + 1]) {
                    y++;
                } else {
                    x--;
                }
                visited[x][y] = true;
            }

            System.out.println("#" + T + " " + y);
        }
    }
}
