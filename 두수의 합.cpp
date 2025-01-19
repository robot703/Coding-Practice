#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n,x,a;
	int start=0, end=0;
	int sum = 0;
	int cnt = 0;
	vector<int>v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> x;

	sort(v.begin(), v.end());

	end = n - 1;
	while (1) {
		if(start >= end)
			break;
		sum = v[start] + v[end];
		if (sum == x) {
			cnt++;
			start++;
			end--;
		}
		else if (sum < x)
			start++;
		else
			end--;	
	}
	printf("%d", cnt);
	return 0;
	
}