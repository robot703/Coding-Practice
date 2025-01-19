#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	
	int n;
	int sum = 0, total = 0;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//3 1 4 3 2
	//0 1 2 3 4
	sort(arr.begin(), arr.end());

	int min = arr[0];
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		total += sum;
	}
	cout << total;
}