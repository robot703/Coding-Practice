#include<iostream>

using namespace std;

int MenOfPassion(int A[],int n) {
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + A[i];// ÄÚµå1
        cnt++;
    }
        return cnt;
}

int main() {
    int n;
    int cnt;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
       arr[i]=0;
    }

    cnt=MenOfPassion(arr, n);

    cout << cnt<<"\n";
    cout << 1;
}