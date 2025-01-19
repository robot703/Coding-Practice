#include<iostream>

using namespace std;

const int MAX_N = 4000000;

int a[MAX_N] = { 0 };  // 전역 배열로 변경
int b[MAX_N] = { 0 };  // 전역 배열로 변경

void primeNum(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        a[i] = i;  // 초기화 부분 수정
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) 
            continue;
        for (int j = 2 * i; j <= n; j += i) {
            a[j] = 0;
        }
        b[cnt++] = a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int sum = 0;
    int count = 0;
    cin >> n;  

    primeNum(n);

    int first = 0, second = 0;

    while (first < n && second < n) {
        if (sum < n) {
            sum += b[second++];
        }
        else {
            sum -= b[first++];
        }

        if (sum == n) {
            count++;
        }
    }

    cout << count;

    return 0;
}
