#include <stdio.h>

#define MAXLINE 1000   /* 画面や配列に一度に保持する最大文字数 */

int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line (modified for Exercise 1-16) */
int main(void)
{
    int len;               /* 現在の行の実際の長さ */
    int max;               /* これまでに見つかった最も長い行の長さ */
    char line[MAXLINE];    /* 現在入力中の行の断片を格納する配列 */
    char longest[MAXLINE]; /* 最も長い行の先頭部分を保存しておく配列 */

    max = 0;
    
    printf("=== Exercise 1-16: Longest Line with Full Length ===\n");
    printf("Please type some lines (Press Ctrl+D to finish):\n");

    while ((len = getline_custom(line, MAXLINE)) > 0) {
        // デバッグ用：途中で切れていても、改行が含まれていれば実際の長さを表示
        printf("[DEBUG] Current line length: %d\n", len);

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    // もし1行でも入力されていたら、最も長かった行の長さと、保持できた内容を表示する
    if (max > 0) {
        printf("\n--- Result ---\n");
        printf("Maximum length found: %d\n", max);
        printf("Longest line (up to %d chars): %s\n", MAXLINE - 1, longest);
    }

    return 0;
}

/* getline_custom: 行を s に読み込み、実際の長さを返す（上限を超えても長さをカウントし続ける） */
int getline_custom(char s[], int lim)
{
    int c, i, total_len;

    total_len = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++total_len) {
        // 配列の容量（lim - 1）を超えない部分だけ実際に文字を保存する
        if (i < lim - 1) {
            s[i] = c;
            i++;
        }
    }
    
    if (c == '\n') {
        total_len++;
        if (i < lim - 1) {
            s[i] = c;
            i++;
        }
    }
    
    s[i] = '\0'; // 文字列の終端
    
    // 配列に入り切らないほど長くても、本当の文字数（total_len）を返すのがポイント
    return total_len;
}

/* copy: from の中身を to にコピーする関数 */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}