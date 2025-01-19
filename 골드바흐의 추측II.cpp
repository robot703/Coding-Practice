#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int>primeNum;

void primeNumberII() {//아리토스테네스의 체
	int n = 100;
	int a = 0;
	vector<bool> arr(n + 1);

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i]) 
			continue;
		for (int j = i + i; j <= n; j += i)
			arr[j] = true;
	}
	for (int i = 2; i <= n; i++)
		if (!arr[i]) {
			primeNum.push_back(i);
		}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	primeNumberII();

	int n;
	int x = 0;
	while (x!=100000)
	{
		cin >> n;
		bool escape = false;
		if (n == 0)
			return 0;
		for (int i = 0; i < primeNum.size(); i++) {
			if (i == primeNum.size() - 1)
				cout << "Goldbach's conjecture is wrong." << "\n";
			if (escape == true)
				break;
			for (int j = 0; j < primeNum.size(); j++) {
				if (primeNum[i] + primeNum[j] == n) {
					printf("%d = %d + %d\n", n, primeNum[i], primeNum[j]);
					escape = true;
					break;
				}
			}
		}
		x++;
	}
	
}