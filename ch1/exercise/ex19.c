#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
	char line[MAXLINE];

	while (mgetline(line, MAXLINE) > 0)
	{
		reverse(line);
		printf("%s\n", line);
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

/* 文字列をひっくり返す関数 */
void reverse(char s[])
{
	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	--i;
	if (s[i] == '\n')
	{
		--i; /* 改行文字は末尾に残しておく */
	}

	j = 0;
	while (j < i)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		++j;
		--i;
	}
}