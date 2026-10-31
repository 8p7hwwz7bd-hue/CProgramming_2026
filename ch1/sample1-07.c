#include <stdio.h>

// 1. 関数のプロトタイプ宣言（「下の方にこういう関数を作るよ」とあらかじめ教える）
int power(int base, int n);

int main(void)
{
    int i;

    printf("=== Function Example (Power) ===\n");

    // 0〜9までループさせて、2のi乗と(-3)のi乗を計算して表示する
    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

// 2. 関数の実際の定義（baseをn乗した結果を計算して返す）
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    return p;
}
