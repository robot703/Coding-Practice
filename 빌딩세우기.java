import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 빌딩세우기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        // 8방향 탐색을 위한 배열 (상하좌우 + 대각선)
        int[] dr = {-1, 1, 0, 0, -1, -1, 1, 1};
        int[] dc = {0, 0, -1, 1, -1, 1, -1, 1};

        for (int tc = 0; tc < t; tc++) {
            int n = Integer.parseInt(br.readLine());
            char[][] map = new char[n][n];

            // 입력 받기
            for (int i = 0; i < n; i++) {
                String line = br.readLine();
                for (int j = 0; j < n; j++) {
                    map[i][j] = line.charAt(j);
                }
            }

            int maxHeight = 0; // 최대 높이 저장

            // 각 위치별로 가능한 빌딩 높이 계산
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[i][j] == 'B') continue; // 이미 빌딩이 있는 곳은 건너뜀

                    boolean hasGreenNear = false; // 인접한 G 여부
                    int buildingCount = 0; // 인접한 B 개수

                    // 8방향 탐색
                    for (int k = 0; k < 8; k++) {
                        int nr = i + dr[k];

                        int nc = j + dc[k];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            if (map[nr][nc] == 'G') {
                                hasGreenNear = true;
                            } else if (map[nr][nc] == 'B') {
                                buildingCount++;
                            }
                        }
                    }


                    int height;
                    if (hasGreenNear) {
                        height = 2; // 공원 인접 시 2층까지 가능
                    } else {
                        height = buildingCount + 1; // 인접 빌딩 수 + 1
                    }

                    maxHeight = Math.max(maxHeight, height);
                }
            }

            System.out.println(maxHeight);
        }
    }
}