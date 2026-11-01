#include <stdio.h>

#define NUM_CHARS 128 /* ASCII文字の総数 */

int main(void)
{
	int c, i, j;
	int char_count[NUM_CHARS];

	/* 配列の初期化 */
	for (i = 0; i < NUM_CHARS; ++i)
		char_count[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c < NUM_CHARS)
			++char_count[c];
	}

	printf("\n--- Character Frequency Histogram ---\n");
	for (i = 0; i < NUM_CHARS; ++i)
	{
		/* 1回以上登場した表示可能文字（スペース〜チルダ）のみ出力 */
		if (char_count[i] > 0 && i >= ' ' && i <= '~')
		{
			printf("'%c': ", i);
			for (j = 0; j < char_count[i]; ++j)
				putchar('*');
			putchar('\n');
		}
	}

	return 0;
}