#include <stdio.h>

#define MAXLINE 1000   /* 入力できる1行の最大文字数 */

int max;               /* これまでに見つかった最も長い行の長さ */
char line[MAXLINE];    /* 現在読み込んでいる行 */
char longest[MAXLINE]; /* 一番長かった行を保存しておく場所 */

// プロトタイプ宣言
int getline_custom(void);
void copy(void);

int main(void)
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    // 1行ずつ読み込んで、これまでより長ければ記録する
    while ((len = getline_custom()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }

    // もし1行でも文字があれば、一番長かった行を表示する
    if (max > 0) {
        printf("\n--- Longest Line ---\n");
        printf("%s", longest);
    }

    return 0;
}

/* getline_custom: 行を読み込む関数 */
int getline_custom(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: lineの中身をlongestにコピーする関数 */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}
