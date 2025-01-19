import java.util.*;

class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); // 테스트 케이스 수

        for (int i = 0; i < T; i++) {
            int[] arr = new int[6];
            int sum = 0;
            int max = 0;

            // 입력과 동시에 합계와 최대값 계산
            for (int j = 0; j < 6; j++) {
                arr[j] = sc.nextInt();
                sum += arr[j];
                max = Math.max(max, arr[j]);
            }

            // 사라진 부하의 키 계산
            for (int h = sum + 1; ; h++) {
                if (h % 7 == 0 && h - sum > max) {
                    System.out.println(h - sum);
                    break;
                }
            }
        }
    }
}
