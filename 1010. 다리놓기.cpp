#include <iostream>
using namespace std;

// 조합 계산 함수 (효율적 방식)
long long combination(int n, int k) {
    if (k > n - k) k = n - k; // 대칭성 활용
    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    int n, k;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        cout << combination(k, n) << "\n";

    }
    return 0;
}
