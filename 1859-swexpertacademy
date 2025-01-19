import java.util.*;

class Solution {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        int T = Integer.parseInt(scanner.nextLine());

        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(scanner.nextLine());
            int[] prices = new int[N];

            String[] input = scanner.nextLine().split(" ");
            for (int i = 0; i < N; i++) {
                prices[i] = Integer.parseInt(input[i]);
            }

            long maxProfit = calculateMaxProfit(prices);

            System.out.println("#" + t + " " + maxProfit);
        }

        scanner.close();
    }

    private static long calculateMaxProfit(int[] prices) {
        int n = prices.length;
        long profit = 0;
        int maxPrice = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] > maxPrice) {
                maxPrice = prices[i];
            } else {
                profit += maxPrice - prices[i];
            }
        }

        return profit;
    }
}
