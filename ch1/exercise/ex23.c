#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

int main(void)
{
	int c;
	while ((c = getchar()) != EOF)
	{
		rcomment(c);
	}
	return 0;
}

void rcomment(int c)
{
	int d;
	if (c == '/')
	{
		if ((d = getchar()) == '*')
		{
			in_comment(); /* コメント内に入ったため読み飛ばす */
		}
		else if (d == '/')
		{
			while ((c = getchar()) != '\n' && c != EOF)
				; /* 1行コメントを読み飛ばす */
			putchar('\n');
		}
		else
		{
			putchar(c);
			putchar(d);
		}
	}
	else if (c == '\'' || c == '"')
	{
		echo_quote(c); /* 文字列の中身はそのまま出力 */
	}
	else
	{
		putchar(c);
	}
}

void in_comment(void)
{
	int c, d;
	c = getchar();
	d = getchar();
	while (c != '*' || d != '/')
	{
		c = d;
		d = getchar();
	}
}

void echo_quote(int c)
{
	int d;
	putchar(c);
	while ((d = getchar()) != c)
	{
		putchar(d);
		if (d == '\\')
		{
			putchar(getchar());
		}
	}
	putchar(d);
}