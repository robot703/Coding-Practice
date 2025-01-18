#include <iostream>
using namespace std;

// �� ���ں��� 0�� 1�� ��µǴ� Ƚ���� ������ �迭
int zero[41]; // 0�� ��µǴ� Ƚ��
int one[41];  // 1�� ��µǴ� Ƚ��

void count_fibonacci() {
    // 0�� ���� ����
    zero[0] = 1; // 0�� ���
    one[0] = 0;  // 1�� ������� ����

    // 1�� ���� ����
    zero[1] = 0;  // 0�� ������� ����
    one[1] = 1;   // 1�� ���

    // 2���� 40���� ������� ���
    for (int i = 2; i <= 40; i++) {
        // ���� �� ������ 0�� 1 ��� Ƚ���� ����
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
}

int main() {
    int T;
    cin >> T;

    // �Ǻ���ġ 0,1 ��� Ƚ���� �̸� ���
    count_fibonacci();

    // �� �׽�Ʈ ���̽� ó��
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << zero[N] << " " << one[N] << '\n';
    }

    return 0;
}