#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int n);

int main() {
    int num = 0;
    int t = 0; // ���� �� ����
    int T[6] = { 0, }; // ���� �� ����
    int arr_user[6] = { 0, }; // ����ڰ� �Է��ϴ� ��ȣ�� �����ϴ� �迭
    int arr_computer[6] = { 0, }; // ��ǻ�Ͱ� ������ ��ȣ�� �����ϴ� �迭
    FILE* fp;// ���� �����͸� �����Ѵ�.
    
    srand(time(NULL));

    printf("[6���� �ζǹ�ȣ�� �Է��ϼ���]\n");

    for (int i = 0; i < 6; i++) {
        arr_computer[i] = rand() % 45 + 1;
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ��° �� �Է� : ", i + 1);
        scanf("%d", &arr_user[i]);
        while (arr_user[i] < 1 || arr_user[i] > 45) {
            printf("���) 1~45 ������ ���� �Է��� �ּ���.\n");
            printf("%d ��° �� �Է� : ", i + 1);
            scanf("%d", &arr_user[i]);
        }
    }

    bubbleSort(arr_user, 6);
    bubbleSort(arr_computer, 6);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr_computer[i] == arr_user[j]) {
                T[i] = arr_user[j];
                t++;
            }
        }
    }

    if (t == 0) {
        printf("�����ϴ�.\n");
    }
    else {
        printf("���� ���� %d�� �Դϴ�.\n", t);
        printf("���� �� : ");
        for (int i = 0; i < 6; i++) {
            if (T[i])
                printf("%d ", T[i]);
        }
        printf("\n");
    }

    printf("USER : ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr_user[i]);
    }
    printf("\n");

    printf("COMPUTER : ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr_computer[i]);
    }
    printf("\n");

    fp = fopen("sorted.txt", "w");	// �ؽ�Ʈ ������ ���� ���� ����.
    if (fp != NULL)		// ���� ���⿡ �����Ͽ��ٸ�,
    {
        if (t == 0) {//���� ���� ���� ���
            fprintf(fp,"�����ϴ�.\n");
        }
        else {//���� ���� �ִ� ���
            fprintf(fp, "���� ���� %d�� �Դϴ�.\n", t);
            fprintf(fp, "���� �� : ");
            for (int i = 0; i < 6; i++) {
                if (T[i])
                    fprintf(fp, "%d ", T[i]);
            }
        }

        fprintf(fp, "USER : ");//user�κ�

        for (int i = 0; i < 6; i++) {
            fprintf(fp, "%d ", arr_user[i]);
        }fprintf(fp, "\n");

        fprintf(fp,"COMPUTER : ");//computer�κ�
       
        for (int i = 0; i < 6; i++) {
            fprintf(fp, "%d ", arr_computer[i]);
        }

        fclose(fp);// ������ �ݴ´�.
    }

    return 0;
}

void bubbleSort(int arr[], int n) {//��������
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
