#include<iostream>

using namespace std;

void bubblesort(int *arr, int n) {
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}
}
int main() {
	int n,k;
	int count = 0;
	int m = 0;
	cin >> n>>k;
	
	int *arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bubblesort(arr, n);
	
	while (m!=n) {
		if (k >= arr[m]) {
			count = count + k / arr[m];
			k = k % arr[m];
		}
		m++;
	}
	cout << count;
}