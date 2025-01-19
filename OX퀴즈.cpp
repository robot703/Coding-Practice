#include<stdio.h>
#include<string.h>

int main() {

	int n, total, score;
	int cnt = 1;
	char sum[81];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		total = 0;
		score = 1;

		scanf("%s", sum);
		for (int j = 0; j < strlen(sum); j++) {
			if (sum[j] == 'O') {
				total += score;
				score++;
			}
			else
				score = 1;
		}
		printf("#%d %d\n",cnt, total);
		cnt++;
	}
}