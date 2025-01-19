#include<iostream>

using namespace std;

int main() {
	int a1, a2, c, n;

	cin >> a1 >> a2;

	cin >> c;

	cin >> n;

	int BigO = a1 * n + a2;
	int g = c * n;

	if ((BigO <= g) && (c - a1 >= 0))
		cout << 1;
	else
		cout << 0;

	return 0;
}