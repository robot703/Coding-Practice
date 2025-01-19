#include<iostream>

using namespace std;

int main() {
	int n,a,b,count=0;
	int arr[100][100]={0};
	cin >> n;

	for (int k = 0; k < n; k++) {

		cin >> a >> b;

		for (int i = 100 - (b + 10); i < 100 - b; i++) {
			for (int j = a; j < a+10; j++) {
				arr[i][j] = 1;
			}
		}

	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				count++;
			}
		}
	}
	cout << count;
}