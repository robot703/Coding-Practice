#include<iostream>

using namespace std;
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int N, M;
	int a, b;
	cin >> N >> M;
	int* arr = (int*)calloc(sizeof(int), N+1);

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		cin >> a >>b;
		swap(arr[a], arr[b]);	
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i]<<" ";
	}
}