//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int solution(vector<int> cookie) {
//    int answer = -1;
//    return answer;
//}
//
//int main() {
//
//    int N,value;
//    cin >> N;
//
//    vector<int>v;
//    for (int i = 0; i < N; i++) {
//        cin >> value;
//        v.push_back(value);
//    }
//
//    for (int i = 0; i < N; i++) {
//        cout << v[i];
//    }
//}
#include<iostream>
#include <vector>
#include <iostream>

using namespace std;

int max_cookie(std::vector<int>cookie) {
    int max_cookie = 0;

    for (int l = 0; l < cookie.size() - 1; l++) {
        int sum1 = 0;
        for (int m = l; m < cookie.size(); m++) {
            sum1 += cookie[m];
            int sum2 = 0;
            for (int r = m + 1; r < cookie.size(); r++) {
                sum2 += cookie[r];
                if (sum2 > sum1)
                    break;
                if (sum1 == sum2)
                    max_cookie = std::max(max_cookie, sum1);
            }
        }
    }

    return max_cookie;
}

int main() {
    vector<int> cookie ;  // 예시 입력

    int N, value;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> value;
        cookie.push_back(value);
    }

    int result = max_cookie(cookie);
    cout << result << endl;  // 결과 출력

    return 0;
}