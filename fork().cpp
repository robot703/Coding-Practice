#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main() {
	
	printf("L0\n");
	fork();
	printf("L1\n");
	fork();
	printf("bye\n");

}