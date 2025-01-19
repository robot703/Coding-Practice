#include<iostream>

using namespace std;

int main() {
	
	int n, i = 1, x = 1;
	
	cin >> n;

	while (1) {
		
		if (n - x <= 0)
			break;

		n = n - x;

		x = i * 6;

		i++;

	}
	cout << i;
	

}
