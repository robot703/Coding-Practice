#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main() {
	int N;
	int K;
	
	int cnt = 0;
	cin >> N>>K;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	

	while (K != 0) {
		for (int i = N-1; i >= 0; i--) {
			if (K >= arr[i]) {
				cnt += K / arr[i];
				K %= arr[i];	
			}
		}
		
	}
	cout << cnt;

}
