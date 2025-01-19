#include<iostream>

using namespace std;

int main() {
	int n,sum=0,count=0;

	cin >> n;

	for (int i = 0; i <= n; i++) {
		int a = i;

		while (a != 0) {
			sum += (a % 10);
			a = a / 10;
		}
		sum = sum + i;

		if (sum == n) {
			cout << i;
			count = 1;
			return 0;
		}
		sum = 0;
	}
	if(count==0)
		cout << "0";
	return 0;
}