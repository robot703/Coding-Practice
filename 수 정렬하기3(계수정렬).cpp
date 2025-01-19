#include<iostream>

using namespace std;

int main() {
	int n;
	int num;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == NULL)
			continue;
		else
			cout << arr[i] << "\n";
	}
}