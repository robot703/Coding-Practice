#include<iostream>

using namespace std;

int main() {
	int n, m,k;

	cin >> n;

	int* arr = new int(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> m;
	int b = m;
	while (m>0) {
		cin >> k;
		for (int i = 0; i < b; i++) {
			if (arr[i] == k)
				cout << 1 << "\n";
		}
		m--;
	}

	return 0;

	
}