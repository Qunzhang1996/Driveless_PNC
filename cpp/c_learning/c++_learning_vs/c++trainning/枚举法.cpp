#include<stdio.h>
int main()
{
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			for (int k = 1; k <= 100; k++)
			{
				if (5 * i + 3 * j + k / 3 == 100 && i + j + k == 100)
				{
					printf("����%2dֻ, ĸ��%2dֻ, С��%2dֻ\n", i, j, k);
				}
			}
	return 0;
}