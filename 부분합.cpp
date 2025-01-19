#include<iostream>
#include<algorithm>\

using namespace std;
int arr[100001]; 
int N, M; //S대신 M사용
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i];
    int st=1, en=1, total = arr[1], len = 999999999;
    while(st <= en && en <= N){
        if(total >= M) len = min(len, (en-st+1));
        if(total < M) {
            en++; 
            total += arr[en];
        } else {
            total -= arr[st];
            st++;
        }
    }
    if(len == 999999999) cout << "0";
    else cout << len;
}