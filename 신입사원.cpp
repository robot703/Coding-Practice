#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> N;
        vector<pair<int, int>> v(N);

        for (int j = 0; j < N; j++) {
            cin >> v[j].first >> v[j].second;
        }

        sort(v.begin(), v.end());

        int count = 1;
        int best = v[0].second;

        for (int j = 1; j < N; ++j) {
            if (v[j].second < best) {
                count++;
                best = v[j].second;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
