#include <stdio.h>

int power(int base, int n);

/* power 関数のテスト */
int main(void)
{
	int i;

	for (i = 0; i < 10; ++i)
	{
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	}

	return 0;
}

/* power: base の n 絶（n >= 0）を計算する */
int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
	{
		p = p * base;
	}

	return p;
}