#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;//입력 받기

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];//수열 입력 받기
    }

    int start = 0, end = 0, len = MAX_N + 1, sum = a[0];
    //start : 시작인덱스
    //end : 끝 인덱스
    //len : 최소 길이
    //sum : 부분합
    while (start < n && end < n) {//start와 end가 유효한 인덱스인 경우
        if (sum < s) {// 부분합이 s보다 작을 경우
            ++end;//end를 더하면서 부분합에 값을 더함
            if (end < n) {// 
                sum += a[end];
            }
        }
        else {//부분합이 s보다 크거나 같을 때
            len = min(len, end - start + 1);// 최소 길이 갱신
            sum -= a[start];// 부분합에서 시작값을 빼준다
            ++start;// 시작 인덱스 증가
        }
    }

    if (len == MAX_N + 1) {//len이 갱신되지 않은 경우 
        len = 0;
    }

    cout << len << '\n';
    return 0;
}