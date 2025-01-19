#define _CRT_SECURE_NO_WARNINGS
#define xx	4
#define yy	5
#include<stdio.h>
void main()
{
	int arr[yy][xx] = { 0 };
	int su = 1, to[2] = { 0 };
	int cnt;
	int x = 0, y = 0;

	for (cnt = 0; cnt < (xx * yy); cnt++)
	{
		arr[y][x] = cnt + 1;
		if ((to[0] == 0) && (to[1] == 0))	// x방향 증가
		{
			x++;
			if ((x == xx) || (arr[y][x] != 0))
			{
				x--;
				cnt--;
				to[0] = 1;
				to[1] = 0;
			}
		}
		else if ((to[0] == 1) && (to[1] == 0))	// y방향 증가
		{
			y++;
			if ((y == yy) || (arr[y][x] != 0))
			{
				y--;
				cnt--;
				to[0] = 0;
				to[1] = 1;
			}
		}
		else if ((to[0] == 0) && (to[1] == 1))	// x방향 감소
		{
			x--;
			if ((x == -1) || (arr[y][x] != 0))
			{
				x++;
				y--;
				to[0] = 1;
				to[1] = 1;
			}
		}
		else if ((to[0] == 1) && (to[1] == 1))	// y방향 감소
		{
			y--;
			if (arr[y][x] != 0)
			{
				y++;
				x++;
				to[0] = 0;
				to[1] = 0;
			}
		}
	}

	for (cnt = 0; cnt < (xx * yy); cnt++)
	{
		x = cnt % xx;
		y = cnt / xx;
		if (((cnt % xx) == 0) && (cnt != 0))printf("\n");
		printf("%d\t", arr[y][x]);
	}
	printf("\n");
}

