#include<iostream>

using namespace std;

int main() {
	long long S,sum=0;
	int N = 1, cnt = 0;
	cin >> S;

	while (true)
	{
		sum += N;
		cnt++;
		N++;
		if (sum > S)
			break;
		
	}
	cout << cnt-1;
}