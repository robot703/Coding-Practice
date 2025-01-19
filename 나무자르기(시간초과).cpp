#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {//시간초과
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int n;//나무 개수
	int m;//원하는 나무 길이
	int tree;
	int cnt = 0;
	priority_queue<int, vector<int>, less<int>>pq;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> tree;
		pq.push(tree);
	}

	for (int i = 0; i < m; i++) {
		pq.push(pq.top() - 1);
		pq.pop();
	}
	cout << pq.top();	
}