#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Attack {
    int t, cnt, idx;
    Attack(int t, int cnt, int idx) : t(t), cnt(cnt), idx(idx) {}
};

bool cmp(const Attack& a, const Attack& b) {
    return a.t < b.t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<Attack> attack;
    vector<int> hp(n, 0);
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            attack.emplace_back(b[i], 1, i);
        }
        hp[i] = max(0, b[i] - i - 1);
    }

    sort(attack.begin(), attack.end(), cmp);

    vector<int> ans(n, 0);
    for (auto& a : attack) {
        int cnt = min(k - ans[a.idx], a.cnt);
        ans[a.idx] += cnt;
        for (int i = 0; i < n; i++) {
            hp[i] -= cnt * max(0, a.t - abs(b[i] - b[a.idx]));
        }
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += max(0, hp[i]);
    }
    cout << res << '\n';

    return 0;
}