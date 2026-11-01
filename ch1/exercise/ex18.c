#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);
int remove_trailing(char line[]);

int main(void)
{
	char line[MAXLINE];

	while (mgetline(line, MAXLINE) > 0)
	{
		if (remove_trailing(line) > 0)
		{
			printf("%s\n", line);
		}
	}
	return 0;
}

int mgetline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* 末尾の空白・タブ・改行を綺麗に取り除く関数 */
int remove_trailing(char s[])
{
	int i = 0;

	/* 1. 文字列の一番最後（'\0'）の位置を探す */
	while (s[i] != '\0')
	{
		++i;
	}
	--i; /* '\0' の直前へ */

	/* 2. 末尾から手前へ戻りながら ' ' や '\t' や '\n' をスキップする */
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		--i;
	}

	/* 3. 新しい末尾をセットする */
	if (i >= 0)
	{
		s[i + 1] = '\0'; /* 文字がある場合はその直後に終端記号 */
	}
	else
	{
		s[0] = '\0'; /* 空白しかなかった場合は空行にする */
	}

	return i + 1; /* 残った文字数を返す（0なら空行） */
}