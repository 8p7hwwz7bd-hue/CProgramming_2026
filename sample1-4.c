#include <stdio.h>

/* 記号定数の定義（ここに書くときは最後にセミコロン「;」をつけないのがルールです） */
#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP  20    /* step size */

int main(void)
{
    int fahr;
    float celsius;

    printf("=== Symbolic Constants Example ===\n");

    /* 定数（LOWER, UPPER, STEP）を使ってforループを回す */
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        celsius = 5.0 * (fahr - 32) / 9.0;
        printf("%3d %6.1f\n", fahr, celsius);
    }

    return 0;
}