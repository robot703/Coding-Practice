#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

bool* sieveOfEratosthenes(uint64_t n) {
    bool* primeArray = (bool*)malloc((n + 1) * sizeof(bool));

    if (primeArray == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }

    for (uint64_t i = 0; i <= n; i++) {
        primeArray[i] = true;
    }

    primeArray[0] = primeArray[1] = false;

    for (uint64_t p = 2; p * p <= n; p++) {
        if (primeArray[p] == true) {
            for (uint64_t i = p * p; i <= n; i += p) {
                primeArray[i] = false;
            }
        }
    }

    return primeArray;
}

int main() {
    double n = 925268208991.647217;
    uint64_t nInt = (uint64_t)sqrt(n);
    bool* primeArray = sieveOfEratosthenes(nInt);

    uint64_t primeCount = 0;
    for (uint64_t i = 0; i <= nInt; i++) {
        if (primeArray[i + 1] == true || primeArray[i - 1] == true) {
            primeCount++;
        }
    }

    printf("0부터 %llu까지의 소수의 개수: %llu\n", nInt, primeCount);

    // primeArray 사용 후 메모리 해제
    free(primeArray);

    return 0;
}