#include<iostream>
#include<queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n,b;
	string a;
	cin >> n;

	queue<int>q;

	for (int i = 0; i < n; i++) {
		cin >> a ;
		if (a == "push") {
			cin >> b;
			q.push(b);
		}
		else if (a == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';

		}
		else if (a == "size")
			cout<<q.size()<<"\n";

		else if (a == "empty") {
			if (!q.empty())
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (a == "front") {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (a == "back") {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}

	
}