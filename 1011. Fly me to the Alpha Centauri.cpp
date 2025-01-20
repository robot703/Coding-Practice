#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        long long x, y;
        long long move, max = 0;
        cin >> x >> y;
        while (max * max <= y - x)
            max++;
        max--;
        move = 2 * max - 1;
        long long rem = y - x - max * max;
        rem = (long long)ceil((double)rem / (double)max);
        move += rem;
        printf("%lld\n", move);
    }
}
