#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;


int main() {
	int n,x;
	int start, end;

	cin>> n;
	vector<int>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	start = 0;
	end = n - 1;
	int absMin = 2e9;

	int a, b;

	while (start < end) {
		int sum = v[start] + v[end];
		int absSum = abs(sum);
		if (absMin > absSum) {
			absMin = absSum;
			a = v[start]; 
			b= v[end];
		}
		if (sum > 0)
			end--;
		else
			start++;
	}
	cout << a << " " << b;
}