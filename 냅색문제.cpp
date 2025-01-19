#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	
	int N, C;//N은 물건개수, C는 가방최대무게
	int count = 1;//경우의수

	cin >> N >> C;

	int* bag = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> bag[i];
	}

	int first = 0;
	int second = 0;
	int sum = 0;

	while (first < N && second < N) {
		if (N == 1) {
			if (bag[N - 1] <= C)
				count++; break;
		}

		if (sum <= C) {
			sum += bag[second++];
			count++;
		}
		else {
			sum -= bag[first++];
		}
	}

	cout << count;





}