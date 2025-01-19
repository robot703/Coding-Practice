#include <iostream>
using namespace std;

// 각 숫자별로 0과 1이 출력되는 횟수를 저장할 배열
int zero[41]; // 0이 출력되는 횟수
int one[41];  // 1이 출력되는 횟수

void count_fibonacci() {
    // 0일 때의 개수
    zero[0] = 1; // 0을 출력
    one[0] = 0;  // 1을 출력하지 않음

    // 1일 때의 개수
    zero[1] = 0;  // 0을 출력하지 않음
    one[1] = 1;   // 1을 출력

    // 2부터 40까지 순서대로 계산
    for (int i = 2; i <= 40; i++) {
        // 이전 두 숫자의 0과 1 출력 횟수를 더함
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
}

int main() {
    int T;
    cin >> T;

    // 피보나치 0,1 출력 횟수를 미리 계산
    count_fibonacci();

    // 각 테스트 케이스 처리
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << zero[N] << " " << one[N] << '\n';
    }

    return 0;
}
