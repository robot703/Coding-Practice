#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a;

	priority_queue<int>max_q;
	priority_queue<int, vector<int>, greater<int>>min_q;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (max_q.size() == 0) {
			max_q.push(a);
		}
		else {
			if (max_q.size() == min_q.size()) {
				max_q.push(a);
			}
			else{
				min_q.push(a);
			}


			if (max_q.top() > min_q.top()) {
				int maxtop = max_q.top();
				int mintop = min_q.top();
				max_q.pop();
				min_q.pop();
				max_q.push(mintop);
				min_q.push(maxtop);
			}
		}
		cout << max_q.top() << "\n";
	}

	
}