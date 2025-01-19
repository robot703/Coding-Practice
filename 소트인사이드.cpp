#include<iostream>

using namespace std;

void qsort(int* arr, int start, int end) {
	if (start >= end)
		return;

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (arr[i] >= arr[key]) {
			i++;
		}
		while (arr[j] <= arr[key] && j > start) {
			j--;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}
		else {
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		
	}
	qsort(arr, start, j - 1);
	qsort(arr, j + 1, end);
}

int main() {
	int n,count=-1,index=0;
	cin >> n;
	int a = n;
	while (n != 0) {
		n /= 10;
		count++;
	}
	int* arr = new int[count];
	while (a != 0) {
		arr[index]= a % 10 ;
		a /= 10;
		index++;
	}
	
	qsort(arr, 0, count);
	

	for (int i = 0; i <= count; i++)
		printf("%d", arr[i]);
}