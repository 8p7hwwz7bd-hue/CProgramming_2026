#include <stdio.h>

// プロトタイプ宣言
int add_by_value(int aa, int bb);
int add_by_reference(int *aa, int *bb);

int main(void)
{
    int a, b, sum;

    // --- 1. 値渡し（Call by value）の実験 ---
    printf("=== 1. Call by Value ===\n");
    a = b = 10;
    sum = add_by_value(a, b);
    
    printf("the sum of a, b = %d\n", sum);
    // 値渡しでは、関数内で a や b に 1 を足しても、元の a と b は変わらない（10のまま）
    printf("a = %d, b = %d\n\n", a, b);


    // --- 2. 参照渡し（Call by reference）の実験 ---
    printf("=== 2. Call by Reference (Address) ===\n");
    a = b = 10;
    // 記号 '&' をつけて、変数の「住所（アドレス）」を渡す
    sum = add_by_reference(&a, &b);
    
    printf("the sum of a, b = %d\n", sum);
    // 参照渡しでは、関数側で住所を指定して書き換えるため、元の a と b の値が変わる（11になる）
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

// 1. 値渡しの関数（コピーを受け取るため、元の変数には影響しない）
int add_by_value(int aa, int bb) 
{
    aa += 1; 
    bb += 1;
    return (aa + bb);
}

// 2. 参照渡しの関数（ポインタ '*' を使って、元の変数の場所を直接書き換える）
int add_by_reference(int *aa, int *bb) 
{
    *aa += 1; 
    *bb += 1;
    return (*aa + *bb);
}