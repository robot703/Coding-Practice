import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class 나무높이_14510{
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            int N = sc.nextInt();
            int[] trees = new int[N];

            int max_height = Integer.MIN_VALUE;
            for (int i = 0; i < N; i++) {
                trees[i] = sc.nextInt();
                max_height = Math.max(max_height, trees[i]);
            }

            int ans = Integer.MAX_VALUE;
            // 이게 기본값이다
            ans = Math.min(ans, watering(trees, N, max_height));
            ans = Math.min(ans, watering(trees, N, max_height + 1));
            System.out.println("#" + tc + " " + ans);
        }
    }

    public static int watering(int[] trees, int N, int max_height) {
        int days = 0;
        int ones = 0, twos = 0;

        for (int i = 0; i < N; i++) {
            ones += (max_height - trees[i]) % 2;
            twos += (max_height - trees[i]) / 2;
            // System.out.printf("%d %d\n",ones, twos);
        }

        int mins = Math.min(ones, twos);
        ones -= mins;
        twos -= mins;
        days += mins * 2;

        if (twos == 0)
            days += (ones - 1) * 2 + 1;
        if (ones == 0)
            days += twos + 1 + (twos - 1) / 3;
        return days;
    }
}

/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 나무높이_14510 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            int n = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            int[] arr = new int[input.length];
            int max = 0;

            for (int i = 0; i < input.length; i++) {
                arr[i] = Integer.parseInt(input[i]);
                max = Math.max(arr[i], max);
            }
            int count = 0;

            for (int i = 0; i < input.length; i++) {
                count += max - arr[i];
            }

            System.out.println((count/3)*2+(count%3));

            System.out.println(max + " " + count);
        }
    }
}
*/

