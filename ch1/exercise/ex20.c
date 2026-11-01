#include <stdio.h>

#define TABINC 4 /* タブ幅を4文字に設定 */

int main(void)
{
    int c, pos;

    pos = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int nb = TABINC - ((pos - 1) % TABINC);
            while (nb > 0)
            {
                putchar(' ');
                ++pos;
                --nb;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}