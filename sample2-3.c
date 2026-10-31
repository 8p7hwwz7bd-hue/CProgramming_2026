#include <stdio.h>

/* 8進数や16進数を使ったエスケープシーケンスの定義 */
#define VTAB_OCT  '\013'  /* 8進数による垂直タブ (Vertical Tab) */
#define BELL_OCT  '\007'  /* 8進数によるベル文字 (Alert / Bell) */

#define VTAB_HEX  '\xb'   /* 16進数による垂直タブ */
#define BELL_HEX  '\x7'   /* 16進数によるベル文字 */

int main(void)
{
    printf("=== 1. Bit-pattern Escape Sequence Test ===\n");
    
    // ベル文字（アラーム音）のテスト
    printf("Bell sound (Octal \\007): %c\n", BELL_OCT);
    
    // 垂直タブのテスト（※環境によっては縦に少しスペースが空きます）
    printf("VTAB (Octal \\013) -> [%c] <- here\n", VTAB_OCT);

    printf("Bell sound (Hex \\x7): %c\n", BELL_HEX);
    printf("VTAB (Hex \\xb) -> [%c] <- here\n", VTAB_HEX);

    printf("\n=== 2. Standard Escape Sequences Test ===\n");
    
    // アラーム音を直接文字コード指定で鳴らす
    printf("Alert sound test: \a (beep!)\n");
    
    // 改行やタブのテスト
    printf("Line 1: Hello\nLine 2: \tIndented with Tab\n");

    return 0;
}