#include <string>
#include <vector>
#include <algorithm> //sort()
#include<cmath> //pow

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    vector<int>temp; //�ӽ÷� ���ڵ� �߶� ���� ����

    while (n != 0) //���� �ڸ���
    {
        temp.push_back(n % 10);
        n /= 10;
    }

    sort(temp.begin(), temp.end(), greater<int>()); //����

    for (int i = 0; i < temp.size(); i++) //10�� (temp.size() - i - 1)��
    {
        answer += temp[i] * pow(10, temp.size() - i - 1);
    }

    return answer;
}