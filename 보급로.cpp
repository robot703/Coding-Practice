#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dijkstra(vector<vector<int>>& arr, int n) {
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    dist[0][0] = arr[0][0];
    pq.push({ arr[0][0], {0, 0} });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == n - 1 && y == n - 1) {
            return cost;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int newCost = cost + arr[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({ newCost, {nx, ny} });
                }
            }
        }
    }

    return -1;
}

int main() {
    int testcase = 0;
    int a = 1;
    cin >> testcase;

    while (a <= testcase) {
        int n = 0;
        cin >> n;

        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++) {
                v[i][j] = row[j] - '0';
            }
        }

        int time = dijkstra(v, n);
        cout << "#" << a++ << " " << time << "\n";
    }

    return 0;
}
