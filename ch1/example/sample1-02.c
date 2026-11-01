#include <stdio.h>

int main(void)
{
    // --- 1. 各データ型のサイズを確認する例 ---
    printf("=== Data Type Sizes ===\n");
    printf("char size   : %lu bytes\n", sizeof(char));
    printf("short size  : %lu bytes\n", sizeof(short));
    printf("int size    : %lu bytes\n", sizeof(int));
    printf("long size   : %lu bytes\n", sizeof(long));
    printf("float size  : %lu bytes\n", sizeof(float));
    printf("double size : %lu bytes\n", sizeof(double));

    // --- 2. 華氏・摂氏の温度変換テーブルを表示する例 ---
    printf("\n=== Fahrenheit-Celsius Table ===\n");
    
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius); // \t はタブ（間隔を空ける文字）です
        fahr = fahr + step;
    }

    return 0;
}
