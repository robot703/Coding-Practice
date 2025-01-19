#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string a, string b) {
	int i = 0;
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] != b[i])
				return a[i] < b[i];
		}
	}
	return a.length() < b.length();
}
int main() {
	int n;
	
	cin >> n;
	vector<string>list;
	string arr;
	for (int i = 0; i < n; i++) {
		cin >> arr;
		list.push_back(arr);
	}

	sort(list.begin(), list.end(),compare);
	cout << list[0] << '\n';
	for (int i = 1; i < n; i++) {
		if (list[i - 1] == list[i])
			continue;
		cout << list[i]<<"\n";
	}
}