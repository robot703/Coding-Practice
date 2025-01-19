//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//long combination(long n, long r) {
//	return tgamma(n + 1) /( tgamma(r + 1) * tgamma(n - r + 1));
//}
//
//int main() {
//	long T,N,M;
//	cin >> T;
//	for (long t = 0; t < T; t++) {
//		cin >> N >> M;
//
//		long result = combination(M, N);
//		cout << result << "\n";
//	}
//	return 0;
//}
#include<iostream>
#include<vector>

using namespace std;

vector<vector<long long>> dp;

long long combination(int n, int r) {
    if (dp[n][r] != 0) {
        return dp[n][r];
    }
    if (r == 0 || r == n) {
        return dp[n][r] = 1;  // nC0 = nCn = 1
    }
    else {
        return dp[n][r] = combination(n - 1, r) + combination(n - 1, r - 1);
    }
}

int main() {
    int T, N, M;
    cin >> T;

    dp.resize(31, vector<long long>(31, 0));  // 최대 입력 범위에 맞게 dp 배열 크기 설정

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        long long result = combination(M, N);
        cout << result << "\n";
    }
    return 0;
}
