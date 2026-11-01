/*
 * Exercise 1-11 概念検証用（動作テスト用コード）
 *
 * 【テストすべきケース】
 * 1. 入力が空の場合 (EOF のみ)
 * 2. 空白・タブ・改行のみの入力
 * 3. 1文字だけの単語
 * 4. 連続する空白や改行の後に単語がある場合
 * 5. 記号が含まれる場合
 */

#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("Lines: %d, Words: %d, Chars: %d\n", nl, nw, nc);
    return 0;
}