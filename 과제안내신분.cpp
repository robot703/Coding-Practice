#include<iostream>

using namespace std;

int main() {
	int check[31]={0};
	int n;


	for (int i = 1; i <= 28; i++) {
		cin >> n;
		check[n] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (check[i] == 0)
			cout << i<< "\n";
	}
	
}