#include<iostream>
#include<stdio.h>

using namespace std;

//int main() {//½Ã°£ÃÊ°úÄÚµå
//	int N;
//	int M;
//	int cnt = 0;
//	int a, b, c, d;//xÁÂÇ¥,yÁÂÇ¥
//	cin >> N >> M;
//	int **arr;
//	arr = new int*[N];
//	for (int i = 0; i < N; i++)
//		arr[i] = new int[N];
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		cin >> a >> b >> c >> d;
//		for (int j = a-1; j < c; j++) {
//			for (int k = b-1; k < d; k++)
//				cnt += arr[j][k];
//		}
//		cout << cnt<<"\n";
//		cnt = 0;
//	}
//	
//}
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1024

int dp[MAX + 1][MAX + 1];
int N, M, ans;
int x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x1, x2, y1, y2;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> x;

			if (i == 1 && j == 1) dp[i][j] = x;
			else if (i == 1)
			{
				dp[i][j] = x + dp[i][j - 1];
			}
			else if (j == 1)
			{
				dp[i][j] = x + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = x + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}


	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}

}