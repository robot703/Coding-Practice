#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int count = 0;

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	int *sorted=(int*)malloc(sizeof(int)*count);
	i = left;
	j = mid + 1;
	k = left;

	// 분할 정렬된 list의 합병 
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할
		merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬
		merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 
		merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 
	}
}


int * readFile() {

	int n = 0;
	int cnt = 0;
	int value;
	char* ptr;
	
	
	FILE* pFile = fopen("Sample Data.txt", "r");//파일을 읽어온다
	while (!feof(pFile))//파일이 끝날 때까지 반복
	{
		fscanf(pFile, "%d, ", &value);//변수 단위로 입력을 받는다
		count++;//단어의 개수를 카운팅해준다. 데이터의 양을 알 수 있다
	}
	fclose(pFile);
	int *arr = (int*)malloc(sizeof(int) * count);//데이터 수만큼 배열을 동적할당 해준다

	FILE* pFile1 = fopen("Sample Data.txt", "r");//파일을 읽어준다

	while (!feof(pFile1)) {
		
		for (int i = 0; i < count; i++) {
			fscanf(pFile1, "%d, ",&value);
			arr[i] = value;//데이터를 배열에 저장
		}
		
	}
	return arr;//배열 리턴
	free(arr);
}

void arrayPrint(int* arr, int a) {
	for (int i = 0; i < count;i++) {
		printf("%d : %d\n",i+1, arr[i]);
	}
	
}

int main() {
	double start, end;
	int *arr;

	arr=readFile();
	merge_sort(arr,0,count-1);
	arrayPrint(arr,count);

	return 0;
}


