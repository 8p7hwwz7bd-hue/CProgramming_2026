#include <stdio.h>

// プロトタイプ宣言
char *month_name(int n);

int main(void)
{
    int n;

    printf("=== 5.8-5.9 Initialization of Pointer Arrays ===\n");
    printf("Please enter the month number (1-12): ");
    
    if (scanf("%d", &n) == 1) {
        char *s = month_name(n);
        printf("Month name is: %s\n", s);
    }

    return 0;
}

/* 
 * month_name: n番目の月に対応する文字列へのポインタを返す関数
 */
char *month_name(int n)
{
    /* 
     * static なポインタ配列：
     * 各要素が文字列リテラル（先頭アドレス）を指すポインタになっている
     */
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    // 範囲外の数字の場合は "Illegal month" (name[0]) を返す
    return (n < 1 || n > 12) ? name[0] : name[n];
}
