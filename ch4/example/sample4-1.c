#include <stdio.h>

#define MAXLINE 1000   /* 1行の最大文字数 */

// プロトタイプ宣言
int getline_custom(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould"; /* 探したいキーワード（パターン） */

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int index_pos = 0;

    printf("=== 1. Pattern Search Example (like \"ould\") ===\n");
    printf("Type some sentences (Press Ctrl+D to finish):\n");

    /* 1行ずつ読み込んで、パターンが含まれているかチェックする */
    while (getline_custom(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("Found by strindex -> %s", line);
            
            // Exercise 4-1 の strrindex のテストもここで実行してみる
            index_pos = strrindex(line, pattern);
            printf("  -> Rightmost index of \"%s\" is at: %d\n", pattern, index_pos);
            
            found++;
        }
    }

    return found;
}

/* getline_custom: 行を s に読み込み、その長さを返す */
int getline_custom(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* strindex: t が s の中のどこにあるかを返す（最初に見つかった位置 / 見つからなければ -1） */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

/* 
 * Exercise 4-1: strrindex(s, t)
 * 文字列 s の中で、文字列 t が「右端（一番後ろ）」に出現する位置を返す。
 * 見つからない場合は -1 を返す。
 */
int strrindex(char s[], char t[])
{
    int i, j, k;
    int rightmost = -1; // 見つかった最右の位置を保持する変数

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        // パッチが一致した場合、位置を更新しつつ、さらに後ろに同じパターンがないか探索を続ける
        if (k > 0 && t[k] == '\0') {
            rightmost = i; 
        }
    }
    return rightmost;


