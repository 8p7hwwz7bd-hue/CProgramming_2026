#include<stdio.h>

	int main(void)
{
	int c;

	// Exercise 1-6: (getchar() != EOF) は 0 または 1 になる
	printf("Press any key: ");
	printf("Value of (getchar() != EOF): %d\n", getchar() != EOF);

	// Exercise 1-7: EOF の値を出力する
	printf("Value of EOF: %d\n", EOF);

	return 0;
}