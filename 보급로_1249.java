import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.Arrays;
import java.util.PriorityQueue;

class Point implements Comparable<Point>{
    int x,y,time;

    Point(int x,int y, int time){
        this.x = x;
        this.y = y;
        this.time = time;
    }

    @Override
    public int compareTo(Point other) {
        return this.time - other.time;
    }
}

public class 보급로_1249{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for(int t=1;t<=T; t++){
            int N = Integer.parseInt(br.readLine());
            int [][]map = new int[N][N];
            for(int i=0; i<N; i++){
                String input = br.readLine();
                for(int j=0; j<N; j++){
                    map[i][j] = input.charAt(j)-'0';
                }
            }
            int result = dijkstra(map);
            System.out.println("#"+t+" "+result);
        }
    }

    public static int dijkstra(int[][]map){
        int N = map.length;
        int [][] times = new int[N][N];
        for(int [] row : times){
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        times[0][0] =0;
        PriorityQueue<Point>pq = new PriorityQueue<>();
        pq.add(new Point(0,0,0));

        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};

        while(!pq.isEmpty()) {
            Point current = pq.poll();
            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    int newTime = current.time + map[nx][ny];
                    if (newTime < times[nx][ny]) {
                         times[nx][ny]=newTime;
                        pq.add(new Point(nx, ny, newTime));
                    }
                }
            }
        }
        return times[N-1][N-1];
    }
}