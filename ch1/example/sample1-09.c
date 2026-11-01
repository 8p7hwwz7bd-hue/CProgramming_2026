#include <stdio.h>

#define MAXLINE 1000   /* 入力できる1行の最大文字数 */

// プロトタイプ宣言
int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;               /* 現在の行の長さ */
    int max;               /* これまでに見つかった最も長い行の長さ */
    char line[MAXLINE];    /* 現在入力中の行を格納する配列 */
    char longest[MAXLINE]; /* 最も長い行を保存しておく配列 */

    max = 0;
    
    printf("=== Longest Line Finder ===\n");
    printf("Please type some lines (Press Ctrl+D to finish):\n");

    // 1行ずつ読み込み、文字数が 0 より大きい間（＝入力が終わるまで）繰り返す
    while ((len = getline_custom(line, MAXLINE)) > 0) {
        // これまでの中で一番長かったら、記録を更新する
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    // もし1行でも入力されていたら、一番長かった行を表示する
    if (max > 0) {
        printf("\n--- Longest Line Result ---\n");
        printf("%s", longest);
    }

    return 0;
}

/* getline_custom: 行を s に読み込み、その長さを返す関数 */
int getline_custom(char s[], int lim)
{
    int c, i;

    // 1文字ずつ読み込み、制限数に達するか、改行か、ファイルの終わり(EOF)になるまで繰り返す
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    
    // 改行文字が含まれていた場合、それも配列に保存する
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    
    // 文字列の終わりを表す終端文字 '\0' を末尾につける
    s[i] = '\0';
    
    return i;
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
