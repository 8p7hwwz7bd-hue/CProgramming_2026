#include <stdio.h>

int main(void)
{
	int c;
	int brace = 0, brack = 0, paren = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '{')
			++brace;
		else if (c == '}')
			--brace;
		else if (c == '[')
			++brack;
		else if (c == ']')
			--brack;
		else if (c == '(')
			++paren;
		else if (c == ')')
			--paren;
	}

	if (brace != 0)
		printf("Error: Unbalanced braces {}\n");
	if (brack != 0)
		printf("Error: Unbalanced brackets []\n");
	if (paren != 0)
		printf("Error: Unbalanced parentheses ()\n");

	if (brace == 0 && brack == 0 && paren == 0)
	{
		printf("No syntax errors found.\n");
	}

	return 0;
}