#include<iostream>

using namespace std;

int main() {
	int N;
	int count = 0, max1, max2,rank=1;
	int *countarr;
	int** arr;

	cin >> N;
	
	arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 2);
	}
	countarr = (int*)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1]<arr[j][1]) {
				rank++;
			}
		}
		cout << rank << " ";
		rank = 1;
	}
	
}