#include<iostream>

using namespace std;
int swap(int *a, int *b) {
	int* temp1 = a;
	int* temp2 = b;
	*a = *temp2;
	*b = *temp1;
}
int main() {
	int n;

	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - 1; j++)
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
	}
}