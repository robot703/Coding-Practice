#include<iostream>

using namespace std;

int main() {

	int min = 999999, N, cnt1 = 0, cnt = 0, M, all = 0, sum = 0, a = 0;
	int blackjack[100]={0,};
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> blackjack[i];		
	}
	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N - 1; j++) {
			for (int k = j+1; k < N ; k ++) {

				sum = blackjack[i] + blackjack[j] + blackjack[k];
				if (min > M - sum && M - sum >= 0) {
					min = M - sum;
					all = sum;
					cnt1 = 1;
				}
				
			}
		}
	}
	cout << all;
}

		
		