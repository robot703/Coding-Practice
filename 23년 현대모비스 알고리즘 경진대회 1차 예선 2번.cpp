#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int solution(string s)
{
	int big = 0;
	int cnt = 1;
	string s2;
	s2 = s;

	reverse(s2.begin(), s2.end());

	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s[i] == s2[j]) {
				int n = i;
				for (int k = j + 1; k < s2.length(); k++) {
					if (s[n + 1] == s2[k]) {
						cnt++;
						n++;
					}
					else
						break;
				}

				big = max(cnt, big);
				cnt = 1;
			}
		}
	}

	
	return big;
}
int main() {
	string s;
	cin >> s;
	int result = solution(s);
	cout << result;
}
