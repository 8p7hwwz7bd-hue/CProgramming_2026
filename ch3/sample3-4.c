#include <stdio.h>

int main(void)
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    printf("=== Switch Statement Example ===\n");
    printf("Please type some characters (Press Ctrl+D to finish):\n");

    // 入力を1文字ずつ読み込む
    while ((c = getchar()) != EOF) {
        switch (c) {
            // caseをまとめて書くことで、'0'〜'9'のどれかに当てはまったときの処理を共有できる
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c - '0']++;
                break; // ここでswitch文を抜け出す

            // 空白、改行、タブの場合
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;

            // どれにも当てはまらなかった場合（デフォルト）
            default:
                nother++;
                break;
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