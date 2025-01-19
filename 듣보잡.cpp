#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n, m, count = 0;
    cin >> n >> m;
    string a;
    vector<string> v(n + m); 
    vector<string> v1;

    for (int i = 0; i < n + m; i++) {
        cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end());


    for (int i = 0; i < n + m - 1; i++) { 
        if (v[i] == v[i + 1]) {
            count++;
            v1.push_back(v[i]);
            i++; 
        }
    }
    cout << count<<"\n";

    for (int i = 0; i < v1.size(); i++) {
        cout<<v1[i]<<"\n";
    }
    return 0;
}
