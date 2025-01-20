#include<iostream>

using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++){
		int a, b, result = 1;

		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			result = (result * a) % 10;
		}
		if (result == 0) {
			cout << 10<<"\n";
		}
		else {
			cout << result<<"\n";
		}
	}
	return 0;
}
