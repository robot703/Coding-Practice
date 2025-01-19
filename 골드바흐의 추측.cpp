#include<iostream>
#include<cstdlib>
#include <cmath>

using namespace std;

int main() {

    int number, count = 0, check = 0,arr1=0,arr2=0,sum=0,num;
    int primeNum[10000];
    int arr[1000] = { 0, };
    
    cin >> num;
    for (int n = 0; n < num; n++) {

        cin >> number;
        //소수를 구하기위해 에라토스테네스의 체를 이용했다
        for (int i = 2; i <= number; i++)
        {
            primeNum[i] = i;
        }

        for (int i = 2; i <= sqrt(number); i++)
        {
            // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
            if (primeNum[i] == 0)
                continue;
            // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
            for (int j = i * i; j <= number; j += i)
                primeNum[j] = 0;
        }
        for (int i = 2; i <= number; i++) {
            if (primeNum[i] != 0) {
                count++;//소수의 개수를 세어준다
            }
        }

        //구한 소수를 새로만든 배열에 순서대로 넣어준다
        int j = 0;
        for (int i = 2; i <= number; i++) {

            if (primeNum[i] != 0) {
                arr[j] = primeNum[i];
                j++;
            }
        }   
        
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                
                if (arr[i] + arr[j] == number) {//배열을 하나씩 비교하며 더했을 때 입력한 값과 같은 경우

                    if (abs(arr[j] - arr[i]) <= sum) {//뺏을 떄 절댓값이 작은 경우 변수에 각각 저장
                        arr1 = arr[i];
                        arr2 = arr[j];
                        sum = abs(arr[j] - arr[i]);
                    }
                    else {
                        sum = abs(arr[j] - arr[i]);//뺀값을 sum변수에 저장
                        continue;
                    }                   
                }              
            }     
        }
        sum = 0;
        count = 0;
        check = 0;   
        cout << arr2 << " " << arr1 << "\n";
        arr1 = 0; arr2 = 0;
    }
}
