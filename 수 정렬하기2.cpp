#define _crt_secure_no_warnings
#include <iostream>

using namespace std;

int arr[100000] = { 0 };

int compare(const void* one, const void* two) {
	if (*(int*)one > *(int*)two)
		return 1;
	else if (*(int*)one < *(int*)two)
		return -1;
	else return 0;
}
int main() {
	int n;

	cin >> n;
	

	for (int i = 0; i < n; i++)
		cin>>arr[i];

	qsort(arr, n, sizeof(int), compare);
	for (int i = 0; i < n; i++)
		cout << arr[i]<<"\n";
}