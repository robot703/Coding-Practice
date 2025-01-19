#include<iostream>

using namespace std;

int main() {
	
	int num = 0;
	cin >> num;

	for (int i = 2; i <= num; i++) {
		if (num == 1) {
			cout << "-1" << endl;
			break;
		}
		if (num % i == 0) {
			while (num % i == 0) {
				num /= i;
				cout << i << endl;
			}
		}
	}

}