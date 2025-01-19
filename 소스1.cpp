#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t = 0;
    int n = 0;
    int k = 0;

    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<vector<int>> set;
        int steps = 0;
        bool possible = false;

        while (true) {

            bool equalvalue = true;
            for (int i = 1; i < v.size(); i++) {
                if (v[i] != v[0]) {
                    equalvalue = false;
                    break;
                }
            }
            if (equalvalue) {
                possible = true;
                break;
            }

            bool pass = false;
            for (const auto& seq : set) {
                if (seq == v) {
                    pass = true;
                    break;
                }
            }
            if (pass) {
                break;
            }
            set.push_back(v);

            v.push_back(v[k - 1]);
            v.erase(v.begin());
            steps++;
        }

        if (possible) {
            cout << "#" << test_case << " " << steps << "\n";
        }
        else {
            cout << "#" << test_case << " -1" << "\n";
        }
    }

    return 0;
}