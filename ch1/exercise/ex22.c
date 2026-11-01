#include <stdio.h>

#define MAXCOL 15 /* 1行の最大列数 */
#define TABINC 4

char line[MAXCOL];

int main(void)
{
	int c, pos;
	pos = 0;

	while ((c = getchar()) != EOF)
	{
		line[pos] = c;
		pos++;

		if (c == '\n')
		{
			for (int i = 0; i < pos; i++)
				putchar(line[i]);
			pos = 0;
		}
		else if (pos >= MAXCOL)
		{
			// MAXCOLに達したら改行を挿入
			for (int i = 0; i < pos; i++)
				putchar(line[i]);
			putchar('\n');
			pos = 0;
		}
	}
	return 0;
}