#include <string>
#include <vector>
#include <algorithm> //sort()
#include<cmath> //pow

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    vector<int>temp; //임시로 숫자들 잘라서 넣을 백터

    while (n != 0) //숫자 자르기
    {
        temp.push_back(n % 10);
        n /= 10;
    }

    sort(temp.begin(), temp.end(), greater<int>()); //정렬

    for (int i = 0; i < temp.size(); i++) //10의 (temp.size() - i - 1)승
    {
        answer += temp[i] * pow(10, temp.size() - i - 1);
    }

    return answer;
}