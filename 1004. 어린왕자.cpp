#include <iostream>
#include<cmath>

using namespace std;

bool distance(int a, int b, int c, int d, int r) {
	return (pow(a - c, 2) + pow(b - d, 2)) < pow(r, 2);
}

int main()
{
	int t;
	int cnt = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int cx, cy, cr;
			cin >> cx >> cy >> cr;

			bool start = distance(x1, y1, cx, cy, cr);
			bool end = distance(x2, y2, cx, cy, cr);

			if (start != end) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		cnt = 0;
	}
	return 0;
}

