#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int n);

int main() {
    int num = 0;
    int t = 0; // 같은 값 개수
    int T[6] = { 0, }; // 같은 값 저장
    int arr_user[6] = { 0, }; // 사용자가 입력하는 번호를 저장하는 배열
    int arr_computer[6] = { 0, }; // 컴퓨터가 생성한 번호를 저장하는 배열
    FILE* fp;// 파일 포인터를 선언한다.
    
    srand(time(NULL));

    printf("[6개의 로또번호를 입력하세요]\n");

    for (int i = 0; i < 6; i++) {
        arr_computer[i] = rand() % 45 + 1;
    }

    for (int i = 0; i < 6; i++) {
        printf("%d 번째 수 입력 : ", i + 1);
        scanf("%d", &arr_user[i]);
        while (arr_user[i] < 1 || arr_user[i] > 45) {
            printf("경고) 1~45 사이의 수를 입력해 주세요.\n");
            printf("%d 번째 수 입력 : ", i + 1);
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
        printf("없습니다.\n");
    }
    else {
        printf("같은 값은 %d개 입니다.\n", t);
        printf("같은 값 : ");
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

    fp = fopen("sorted.txt", "w");	// 텍스트 파일을 쓰기 모드로 연다.
    if (fp != NULL)		// 파일 열기에 성공하였다면,
    {
        if (t == 0) {//같은 값이 없는 경우
            fprintf(fp,"없습니다.\n");
        }
        else {//같은 값이 있는 경우
            fprintf(fp, "같은 값은 %d개 입니다.\n", t);
            fprintf(fp, "같은 값 : ");
            for (int i = 0; i < 6; i++) {
                if (T[i])
                    fprintf(fp, "%d ", T[i]);
            }
        }

        fprintf(fp, "USER : ");//user부분

        for (int i = 0; i < 6; i++) {
            fprintf(fp, "%d ", arr_user[i]);
        }fprintf(fp, "\n");

        fprintf(fp,"COMPUTER : ");//computer부분
       
        for (int i = 0; i < 6; i++) {
            fprintf(fp, "%d ", arr_computer[i]);
        }

        fclose(fp);// 파일을 닫는다.
    }

    return 0;
}

void bubbleSort(int arr[], int n) {//버블정렬
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
