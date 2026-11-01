#include <stdio.h>

#define BUFSIZE 100
int buf[BUFSIZE]; // int型にすることで EOF (-1) をそのまま保持可能
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
    if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}

int main(void) {
    ungetch(EOF); // EOF を押してみる
    int c = getch();
    if (c == EOF) {
        printf("Successfully read EOF from buffer!\n");
    }
    return 0;
}
