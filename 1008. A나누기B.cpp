#include <iostream>
#include <iomanip>
#include <sstream> // 문자열 스트림 사용
using namespace std;

int main() {
    double A, B;
    cin >> A >> B;

    stringstream ss;
    ss << fixed << setprecision(9) << A / B; // 소수점 9자리까지 출력
    string result = ss.str();

    // 불필요한 0 제거
    result.erase(result.find_last_not_of('0') + 1); // 마지막 '0'이 아닌 문자를 찾음
    if (result.back() == '.') { // 소수점만 남으면 제거
        result.pop_back();
    }

    cout << result << endl;
    return 0;
}
