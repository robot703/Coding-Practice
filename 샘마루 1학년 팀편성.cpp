#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> const& v)
{
    for (string i : v) {
        cout << i << ' ';
    }
}

int main()
{
    vector<string> v = { "오현승", "안정훈", "조재영", "허채민", "강인성","이준호", "신승우", "신정민", "한철연","윤태식",
                         "이충민", "최나현", "김세훈", "김승재", "황지연", "신혜원", "장재혁", "이휘준", "김대희", "전수혁", "윤준영" };
    int n = v.size();


    for (int i = 0; i < n - 1; i++)
    {
        int j = i + rand() % (n - i);
        swap(v[i], v[j]);
    }

    int teamSize = 4; 
    int numTeams = n / teamSize; 

    for (int i = 0; i < numTeams; i++) {
        cout << "Team " << i + 1 << ":\n";
        for (int j = i * teamSize; j < (i + 1) * teamSize; j++) {
            cout << v[j] << "\n";
        }
        cout << "\n";
    }

    cout << v[20];


    return 0;
}
