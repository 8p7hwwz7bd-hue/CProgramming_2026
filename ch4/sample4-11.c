#include <stdio.h>
#ifndef EXAMPLE_H
#define EXAMPLE_H
// （ヘッダーの中身）
#endif
/*
 * -----------------------------------------------------------------
 * 【1. マクロ置換 (Macro Substitution)】
 * -----------------------------------------------------------------
 * ・#define を使って、定数だけでなく「引数付きのマクロ」を定義できます。
 * ・展開時は単なる文字列の置き換えが行われます。
 */
#define SQUARE(x) ((x) * (x))   /* 引数には必ずカッコをつけるのが安全のコツ */

/*
 * -----------------------------------------------------------------
 * 【2. 条件付きコンパイル (Conditional Inclusion)】
 * -----------------------------------------------------------------
 * ・#ifdef / #ifndef / #if などの指令を使うことで、
 *   「特定の条件を満たしているときだけコンパイルに含める」ことができます。
 */
#define DEBUG 1  // デバッグモードを有効にする

int main(void)
{
    printf("=== 1. Macro Substitution Test ===\n");
    int a = 5;
    printf("Square of %d is %d\n\n", a, SQUARE(a));

    printf("=== 2. Conditional Compilation Test ===\n");
    
    /* #ifdef の例：DEBUG が定義されている場合のみコンパイル・実行される */
    #ifdef DEBUG
        printf("[DEBUG] Debug mode is ON. Variable a = %d\n", a);
    #endif

    /* #if の例：数値の条件による切り替え */
    #if DEBUG == 1
        printf("[INFO] Conditional compilation by #if value.\n");
    #else
        printf("[INFO] Production mode.\n");
    #endif

    return 0;
}