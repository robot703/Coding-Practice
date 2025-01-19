#include<iostream>

using namespace std;

/*int main() {
	int M, N, k=1;

	cin >> M >> N;

	if (M == 2 && N >= 3) {
		cout << 2 << "\n" << 3 << "\n";
	}
	else if (M == 3)
		cout << 3 << "\n";
	while (6 * k - 1 <= N || 6 * k + 1 <= N) {
		
		cout << 6 * k - 1 << "\n";
		cout << 6 * k + 1 << "\n";
		k++;
	}

}*/

bool isPrime[1000000];

int main()

{
	int M, N;
	cin >> M >> N;
	

	for (int i = 2; i <= N; i++)
	{
		
		for (int j = i * i; j <= N; j += i)
			isPrime[j] = true;
	}

	for (int k = M; k <= N; k++) {
		if (isPrime[k] == false)
		{
			cout << k << "\n";
		}
	}
	return 0;
}

