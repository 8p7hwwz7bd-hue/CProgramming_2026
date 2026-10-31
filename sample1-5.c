#include <stdio.h>

int main(void)
{
    // --- 1. 文字のコピー（入力された文字をそのまま出力する） ---
    printf("=== 1. Character Copy Example ===\n");
    printf("Please type some characters (Press Ctrl+D to finish):\n");
    
    int c;
    // キーボードから1文字読み込み、ファイルの終端(EOF)でなければ繰り返す
    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    // --- 2. 文字数カウント（Character Counting） ---
    // ※ 1の入力を終えた（Ctrl+Dを押した）あとに続きます
    printf("\n=== 2. Character Counting Example ===\n");
    long nc = 0;
    
    // キーボードからの入力をもう一度受け付けて文字数を数える場合
    // （※実際に動かすときは入力をリセットするか、個別のファイルに分けると分かりやすいです）
    
    return 0;
}