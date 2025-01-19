#include<iostream>

using namespace std;

int solution(int N, int P) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum +=i;
		if (sum == P) {
			sum--;
		}
	}
	return sum;
}

int main() {
	int n = 0;
	int p = 0;
	int t = 0;
	cin >> t;
	

	for (int k = 0; k < t; k++) {
		cin >> n >> p;
		int a=solution(n, p);
		cout << a << "\n";
	}
	
}