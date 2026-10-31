#include <stdio.h>

int main(void)
{
    int lower = 0;
    int upper = 300;
    int step = 20;
    int fahr;
    float celsius; // 摂氏の計算結果を小数で正しく受け取るため float型 に変更しています

    // --- 1. for文を使った温度変換の例 ---
    printf("=== 1. For Statement Example ===\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        // ★小数として正しく計算させるため 5.0 と 9.0 にしています
        celsius = 5.0 * (fahr - 32) / 9.0;
        printf("%3d %6.1f\n", fahr, celsius);
    }

    // --- 2. フラグ（flag）を使った while ループの例 ---
    printf("\n=== 2. While Loop with Flag Example ===\n");
    fahr = lower;
    int flag = 1;
    while (flag) {
        celsius = 5.0 * (fahr - 32) / 9.0;
        printf("%d\t%.1f\n", fahr, celsius);
        fahr = fahr + step;
        
        // 温度が上限（upper）を超えたらフラグを0にしてループを抜ける
        if (fahr > upper) {
            flag = 0;
        }
    }

    return 0;
}