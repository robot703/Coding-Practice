#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // �Է¹��� ���ڿ��� �ִ� ����
#define MAX_ROW 5   // 2���� �迭�� �ִ� �� ��
#define MAX_COL 100 // 2���� �迭�� �ִ� �� ��

int main() {
    char arr[MAX_ROW][MAX_COL];
    int i, j, len;

    // 5���� ���ڿ� �Է¹ޱ�
    
    for (i = 0; i < MAX_ROW; i++) {
        scanf("%s", arr[i]);
        len = strlen(arr[i]);

        // �Է¹��� ���ڿ��� ���̸�ŭ���� �� ũ�� ����
        for (j = len; j < MAX_COL; j++) {
            arr[i][j] = '\0';
        }
    }

    // �� ���ڿ��� ���η� ����ϱ�
    
    for (j = 0; j < MAX_COL; j++) {
        for (i = 0; i < MAX_ROW; i++) {
            if (arr[i][j] != '\0') { // ���ڿ��� ������ ��� �ߴ�
                printf("%c", arr[i][j]);
            }
        }
         // ���� ���� �Ѿ ������ �ٹٲ�
    }

    return 0;
}
