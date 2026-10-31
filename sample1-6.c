#include <stdio.h>

int main(void)
{
    int c, i, nwhite, nother;
    int ndigit[10]; // 0〜9までの数字の出現回数を数えるための配列（10個の箱）

    nwhite = nother = 0;

    // 配列の箱の中身をすべて 0 で初期化する
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    printf("=== Array Counting Example ===\n");
    printf("Please type some characters (Press Ctrl+D to finish):\n");

    // 入力を1文字ずつ読み込む
    while ((c = getchar()) != EOF) {
        // 読み込んだ文字が数字（'0'から'9'の間）かどうかを判定
        if (c >= '0' && c <= '9') {
            // 文字の数字（'0'など）から実際の数値（0など）に変換してカウントを増やす
            ndigit[c - '0']++;
        } 
        // 空白、タブ、改行のいずれかの場合
        else if (c == ' ' || c == '\n' || c == '\t') {
            nwhite++;
        } 
        // それ以外の文字の場合
        else {
            nother++;
        }
    }

    // --- 結果の出力 ---
    printf("\n--- Result ---\n");
    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}