#include<iostream>
#include <cmath>
using namespace std;

int main() {
	int n, root, count = 0;

	while (1) {
		cin >> n;

		if (!n)
			break;

		for (int i = n + 1; i <= n * 2; i++) {
			root = sqrt(i);
			if (root == 1 && i != 1) {
				count++;
				continue;
			}
			if (i % 2) {
				for (int j = 2; j <= root; j++) {
					if (!(i % j))
						break;

					if (j == root)
						count++;
				}
			}

			
		}
		cout << count << endl;
		count = 0;
	}
}