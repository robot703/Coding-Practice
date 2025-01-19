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
        //�Ҽ��� ���ϱ����� �����佺�׳׽��� ü�� �̿��ߴ�
        for (int i = 2; i <= number; i++)
        {
            primeNum[i] = i;
        }

        for (int i = 2; i <= sqrt(number); i++)
        {
            // primeNum[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
            if (primeNum[i] == 0)
                continue;
            // i*k (k<i) ������ ���� �̹� �˻������Ƿ� j�� i*i ���� �˻����ش�.
            for (int j = i * i; j <= number; j += i)
                primeNum[j] = 0;
        }
        for (int i = 2; i <= number; i++) {
            if (primeNum[i] != 0) {
                count++;//�Ҽ��� ������ �����ش�
            }
        }

        //���� �Ҽ��� ���θ��� �迭�� ������� �־��ش�
        int j = 0;
        for (int i = 2; i <= number; i++) {

            if (primeNum[i] != 0) {
                arr[j] = primeNum[i];
                j++;
            }
        }   
        
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                
                if (arr[i] + arr[j] == number) {//�迭�� �ϳ��� ���ϸ� ������ �� �Է��� ���� ���� ���

                    if (abs(arr[j] - arr[i]) <= sum) {//���� �� ������ ���� ��� ������ ���� ����
                        arr1 = arr[i];
                        arr2 = arr[j];
                        sum = abs(arr[j] - arr[i]);
                    }
                    else {
                        sum = abs(arr[j] - arr[i]);//������ sum������ ����
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
