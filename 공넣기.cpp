#include<iostream>

using namespace std;

int main() {
	int N;
	int M;
	int a, b,c;
	

	cin >> N >> M;

	int* arr = (int*)calloc(sizeof(int), N+1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b>>c;
		for (int j = a; j <= b; j++) {
			arr[j] = c;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << arr[i]<<" ";
}