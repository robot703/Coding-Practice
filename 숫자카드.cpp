#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;
/*int arr3[50001] = {0};
int binary(int *arr1,int n, int key) {
	int right = n - 1;
	int left = 0;
	int i = 0;
	while (left <= right) {
		int mid = (right + left) / 2;
		if (arr1[mid] == key) {
			arr3[i] = 1;
			i++;
			break;
		}
		if (arr1[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;

}
int main() {
	int* arr1=NULL;
	int* arr2=NULL;
	int n, m, count = 0,key;
	
	cin >> n;
	
	arr1 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	
	cin >> m;
	arr2 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	sort(arr1, arr1 + n);
	for (int i = 0; i < m; i++) {
		key = arr2[i];
		binary(arr1,n,key);
		
	}
	for (int i = 0; i < m; i++)
		cout << arr3[i] << "";
	free(arr1);
	free(arr2);
	

}*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int len, temp;
	vector<int> v;
	cin >> len;

	while (len--) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> len;
	while (len--) {
		cin >> temp;
		cout << binary_search(v.begin(), v.end(), temp) << ' ';
	}

}