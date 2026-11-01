#include <stdio.h>

#define MAXWORDLEN 15 // カウントする最大単語長
#define IN  1
#define OUT 0

int main(void) {
    int c, i, j, len = 0, state = OUT;
    int word_lengths[MAXWORDLEN + 1] = {0};

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (len > MAXWORDLEN) {
                    len = MAXWORDLEN;
                }
                if (len > 0) {
                    ++word_lengths[len];
                }
                len = 0;
                state = OUT;
            }
        } else {
            state = IN;
            ++len;
        }
    }

    printf("\n--- Word Length Histogram ---\n");
    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("%2d: ", i);
        for (j = 0; j < word_lengths[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}