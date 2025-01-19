#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // 입력받을 문자열의 최대 길이
#define MAX_ROW 5   // 2차원 배열의 최대 행 수
#define MAX_COL 100 // 2차원 배열의 최대 열 수

int main() {
    char arr[MAX_ROW][MAX_COL];
    int i, j, len;

    // 5개의 문자열 입력받기
    
    for (i = 0; i < MAX_ROW; i++) {
        scanf("%s", arr[i]);
        len = strlen(arr[i]);

        // 입력받은 문자열의 길이만큼으로 열 크기 지정
        for (j = len; j < MAX_COL; j++) {
            arr[i][j] = '\0';
        }
    }

    // 각 문자열을 세로로 출력하기
    
    for (j = 0; j < MAX_COL; j++) {
        for (i = 0; i < MAX_ROW; i++) {
            if (arr[i][j] != '\0') { // 문자열이 끝나면 출력 중단
                printf("%c", arr[i][j]);
            }
        }
         // 다음 열로 넘어갈 때마다 줄바꿈
    }

    return 0;
}
