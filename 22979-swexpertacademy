import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 테스트 케이스의 수 입력
        int t = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < t; i++) {
            // 문자열 S 입력
            String s = scanner.nextLine();

            // 연산의 횟수 K 입력
            int k = Integer.parseInt(scanner.nextLine());

            long totalRotation = 0;
            String[] operations = scanner.nextLine().split(" ");
            for (String operation : operations) {
                totalRotation += Long.parseLong(operation);
            }

            // 문자열 길이로 나눈 나머지 값만큼만 실제 회전
            totalRotation %= s.length();

            // 음수 회전을 양수로 변환
            if (totalRotation < 0) {
                totalRotation += s.length();
            }

            // 문자열 회전
            s = s.substring((int) totalRotation) + s.substring(0, (int) totalRotation);

            // 결과 출력
            System.out.println(s);
        }

        scanner.close();
    }
}
