#include <iostream>

using namespace std;
#define MAX 9

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int k) { //현재 위치
    if (k == M) { //목표인 M까지 도달했다면
        for (auto i = 0; i < M; i++)
            cout << arr[i] << " "; //arr에 저장한 값 M개 만큼 출력
        cout << "\n";
    }
    else { //목표에 도달하지 않았다면
        for (auto i = 1; i <= N; i++) {
            if (!visited[i]) { //방문 안 했다면
                visited[i] = true; //방문 표시
                arr[k] = i; // i값을 arr에 저장
                dfs(k + 1); //더 깊게 들어가자. (M까지)
                visited[i] = false; //백트래킹 설정
            }
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}