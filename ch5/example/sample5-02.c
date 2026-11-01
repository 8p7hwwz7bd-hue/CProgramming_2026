#include <stdio.h>

/* プロトタイプ宣言 */
void swap_wrong(int x, int y);      // 値渡し（失敗例）
void swap_correct(int *px, int *py); // ポインタを使った参照渡し（成功例）

int main(void)
{
    /*
     * -----------------------------------------------------------------
     * 【1. 値渡し (Call by value) の限界】
     * -----------------------------------------------------------------
     * ・普通に関数を呼ぶと「値のコピー」が渡されるため、
     *   関数の中で書き換えても、大元の変数は変わりません。
     */
    int a = 5, b = 10;

    printf("=== 1. Call by Value Test ===\n");
    printf("Before swap_wrong: a = %d, b = %d\n", a, b);
    
    swap_wrong(a, b); // コピーが渡されるだけなので入れ替わらない
    
    printf("After swap_wrong:  a = %d, b = %d (Not changed!)\n\n", a, b);


    /*
     * -----------------------------------------------------------------
     * 【2. ポインタ引数による参照渡し (Call by reference)】
     * -----------------------------------------------------------------
     * ・変数の「アドレス（&a, &b）」を渡すことで、
     *   関数側から大元のメモリに直接アクセスして書き換えることができます。
     */
    printf("=== 2. Call by Reference Test (Pointer) ===\n");
    printf("Before swap_correct: a = %d, b = %d\n", a, b);
    
    swap_correct(&a, &b); // アドレス（住所）を渡す
    
    printf("After swap_correct:  a = %d, b = %d (Successfully swapped!)\n", a, b);

    return 0;
}

/* 
 * swap_wrong: 値渡しのため、関数内の x と y が入れ替わるだけで終わる
 */
void swap_wrong(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

/* 
 * swap_correct: ポインタで受け取り、アドレスの指す先（*px, *py）を直接入れ替える
 */
void swap_correct(int *px, int *py)
{
    int temp;

    temp = *px;     /* px が指す値まり a の値目を一時保存 */
    *px = *py;    /* py が指す値（b）を px の指す場所（a）に代入 */
    *py = temp;     /* 一時保存しておいた値を py の指す場所（b）に代入 */
}
