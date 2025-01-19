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

	// ���� ���ĵ� list�� �պ� 
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// ���� �ִ� ������ �ϰ� ����
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	// ���� �ִ� ������ �ϰ� ����
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

// �պ� ����
void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ����
		merge_sort(list, left, mid); // ���� �κ� ����Ʈ ����
		merge_sort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� 
		merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� 
	}
}


int * readFile() {

	int n = 0;
	int cnt = 0;
	int value;
	char* ptr;
	
	
	FILE* pFile = fopen("Sample Data.txt", "r");//������ �о�´�
	while (!feof(pFile))//������ ���� ������ �ݺ�
	{
		fscanf(pFile, "%d, ", &value);//���� ������ �Է��� �޴´�
		count++;//�ܾ��� ������ ī�������ش�. �������� ���� �� �� �ִ�
	}
	fclose(pFile);
	int *arr = (int*)malloc(sizeof(int) * count);//������ ����ŭ �迭�� �����Ҵ� ���ش�

	FILE* pFile1 = fopen("Sample Data.txt", "r");//������ �о��ش�

	while (!feof(pFile1)) {
		
		for (int i = 0; i < count; i++) {
			fscanf(pFile1, "%d, ",&value);
			arr[i] = value;//�����͸� �迭�� ����
		}
		
	}
	return arr;//�迭 ����
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


