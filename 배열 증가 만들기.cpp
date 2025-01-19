#include<iostream>

using namespace std;

int main() {
	int n, m,k,a=1;
	int cnt = 1;
	cin >> n >> m>>k;
	int** arr = new int*[n];
	for (int i = 0; i < m; i++)
		arr[i] = new int[m];

	if (max(m, n) + min(m, n) - 1 <= k)
		cout << "YES\n";
	else {
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = cnt++;
			cout << arr[i][j]<<" ";
		}
		cout << "\n";
		cnt = 1;
		cnt += a++;
	}

	
}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, m, k;
//vector<int> path;
//
//int binary_search(int start, int end, int k) {
//    while (start <= end) {
//        int mid = (start + end) / 2;
//        if (path[mid] <= k) {
//            start = mid + 1;
//        }
//        else {
//            end = mid - 1;
//        }
//    }
//    return end;
//}
//
//void backtrack(int x, int y, bool visited[], int arr[][6]) {
//    if (x == n + 1 && y == 1) {
//        cout << "YES" << endl;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                cout << arr[i][j] << " ";
//            }
//            cout << endl;
//        }
//        exit(0);
//    }
//
//    int start = 1;
//    int end = k;
//    if (x == 1 && y == 1) {
//        start = 2;
//    }
//    else {
//        start = arr[x - 1][y] + 1;
//    }
//    int idx = binary_search(0, path.size() - 1, y + n - x - 1);
//    if (idx != -1) {
//        end = min(end, path[idx]);
//    }
//
//    for (int i = start; i <= end; i++) {
//        if (!visited[i]) {
//            visited[i] = true;
//            arr[x][y] = i;
//            backtrack(x + (y == m), (y % m) + 1, visited, arr);
//            visited[i] = false;
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m >> k;
//    path.push_back(2);
//    for (int i = 1; i <= n + m - 2; i++) {
//        path.push_back(path.back() + i);
//    }
//    if (k < path[n - 1]) {
//        cout << "NO" << endl;
//        return 0;
//    }
//    bool visited[k + 1] = { false };
//    int arr[n + 1][6] = { 0 };
//    backtrack(1, 1, visited, arr);
//    cout << "NO" << endl;
//    return 0;
//}