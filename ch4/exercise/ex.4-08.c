#include <stdio.h>

int buf = EOF; // バッファ配列ではなく単一の変数を使用

int getch(void) {
    int c;
    if (buf != EOF) {
        c = buf;
        buf = EOF;
    } else {
        c = getchar();
    }
    return c;
}

void ungetch(int c) {
    if (buf != EOF) printf("ungetch: too many characters\n");
    else buf = c;
}

int main(void) {
    int c = getch();
    ungetch(c); // 読み込んだ1文字を押し戻す
    printf("Read back: %c\n", getch());
    return 0;
}
