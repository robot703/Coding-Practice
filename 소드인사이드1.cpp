#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char str[10];

	scanf("%s", str);

	for (int i = 0; i < strlen(str)-1; i++) {
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] < str[j + 1]) {
				char temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	printf("%s", str);

	return 0;
}