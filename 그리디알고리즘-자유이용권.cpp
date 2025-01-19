#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long n,a;
	long cnt = 0;
	cin >> n;

	priority_queue<int, vector<int>, less<int>>pq;
	queue<int> q;



	for (long i = 0; i < n; i++) {
		cin >>a;
		pq.push(a);//3 1 1
	}

	if (pq.size() == 1) {
		cnt=1;
	}
	else if (pq.size() == 2) {
		pq.pop();
		cnt = pq.top() * 2 + 1;
	}
	else if(pq.size()>2) {
		q.push(pq.top() - 1);
		pq.pop();
		q.push(pq.top() - 1);
		pq.pop();
		cnt += 2;
		while (true) {
			if ((pq.top()==0&&q.front()==0&&q.back()==0)||q.size()==1) 
				break;
			pq.push(q.front());
			q.pop();
			q.push(pq.top() - 1);
			pq.pop();
			cnt++;
		}
	}
	cout << cnt;
}

#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long n, a;
	long cnt = 0;

	cin >> n;
	priority_queue<long, vector<long>, less<long>>pq;

	queue<long>q;
	long i;
	for (i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}

	while (!pq.empty()) {
		if (pq.size() == 1) {
			q.push(pq.top() - 1);
			pq.pop();
			cnt++;
			break;
		}
		q.push(pq.top() - 1);
		pq.pop();
		q.push(pq.top() - 1);
		pq.pop();
		cnt += 2;
		while (!q.empty()) {
			if (q.front() != 0) {
				pq.push(q.front());
				q.pop();
			}
			else
				q.pop();
		}
	}

	cout << cnt;
}