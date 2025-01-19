#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;//�Է� �ޱ�

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];//���� �Է� �ޱ�
    }

    int start = 0, end = 0, len = MAX_N + 1, sum = a[0];
    //start : �����ε���
    //end : �� �ε���
    //len : �ּ� ����
    //sum : �κ���
    while (start < n && end < n) {//start�� end�� ��ȿ�� �ε����� ���
        if (sum < s) {// �κ����� s���� ���� ���
            ++end;//end�� ���ϸ鼭 �κ��տ� ���� ����
            if (end < n) {// 
                sum += a[end];
            }
        }
        else {//�κ����� s���� ũ�ų� ���� ��
            len = min(len, end - start + 1);// �ּ� ���� ����
            sum -= a[start];// �κ��տ��� ���۰��� ���ش�
            ++start;// ���� �ε��� ����
        }
    }

    if (len == MAX_N + 1) {//len�� ���ŵ��� ���� ��� 
        len = 0;
    }

    cout << len << '\n';
    return 0;
}