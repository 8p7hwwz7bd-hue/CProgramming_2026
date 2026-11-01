#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch(int c) { if (bufp >= BUFSIZE) printf("ungetch: too many chars\n"); else buf[bufp++] = c; }

// 文字列 s を逆順でバッファに押し戻す
void ungets(char s[]) {
    int len = strlen(s);
    while (len > 0) {
        ungetch(s[--len]);
    }
}

int main(void) {
    char test[] = "Hello World";
    int c;

    ungets(test); // "Hello World" を入力バッファにセット

    while ((c = getch()) != EOF && bufp > 0) {
        putchar(c);
    }
    printf("\n");
    return 0;
}
