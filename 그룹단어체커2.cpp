#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	int cnt=0, x=0;
	bool a = false;

	cin >> n;
	string c;
	
	for (int i = 0; i < n; i++) {
		cin >> c;//문자입력
		if (c.length() == 1 || c.length() == 2) {//문자길이가 1이나 2인 경우
			continue;
		}

		else {//문자 길이가 3이상인 경우
			for (int j = 0; j < c.length() - 1; j++) {
				for (int k = j + 1; k < c.length(); k++) {
					if (c[j] == c[k]) {//문자가 같은경우 
						if (x > 0) {//이미 중복된 문자인 경우 cnt증가해주고 바로 탈출
							cnt++;
							a = true;
							break;
						}	
					}
					else//다른 문자인경우 x를 증가
						x++;
				}
				x = 0;
				if (a == true) {
					a = false;
					break;
				}
			}
			
		}
	}
	cout << n-cnt;//전체 개수에서 중복됐던 문자개수 빼기
}