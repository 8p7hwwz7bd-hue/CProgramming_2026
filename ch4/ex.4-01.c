#include <stdio.h>
#include <string.h>

// Exercise 4-1: 文字列 s の中で文字パターン t が一番右側（最後）に見つかる位置を返す関数
int strrindex(char s[], char t[]) {
    int i, j, k;
    int pos = -1; // 見つかった位置を記録（見つからなければ -1 のまま）

    // 先頭から順番にパターンを探していく
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        // パターンが見つかったら、直ちに return せず pos に位置を上書き保存する
        if (k > 0 && t[k] == '\0') {
            pos = i;
        }
    }

    return pos; // 一番最後に上書きされた位置（一番右側のインデックス）を返す
}

int main() {
    char s[] = "abcdedfabcde";
    char t[] = "abc";

    int index = strrindex(s, t);

    printf("文字列 s: \"%s\"\n", s);
    printf("探すパターン t: \"%s\"\n", t);
    printf("一番右側で見つかった位置 (rightmost index): %d\n", index);

    return 0;
}
