#include <stdio.h>
#include <string.h>

// プロトタイプ宣言
void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    /*
     * -----------------------------------------------------------------
     * 【1. do-while ループの基本構文】
     * -----------------------------------------------------------------
     * do {
     *     statement;          // まず最初にこの処理が実行される
     * } while (expression); // 最後に条件式をチェックする（セミコロンが必要！）
     */
    printf("=== 1. Do-While Basic Test ===\n");
    int count = 0;
    do {
        printf("Executed at least once! count = %d\n", count);
        count++;
    } while (count < 2);


    /*
     * -----------------------------------------------------------------
     * 【2. itoa 関数のテスト（整数 -> 文字列変換）】
     * -----------------------------------------------------------------
     */
    printf("\n=== 2. Itoa Function Test ===\n");
    int num = -12345;
    char str[100]; // 変換した文字列を格納する配列

    itoa(num, str);
    printf("Converted integer %d to string: \"%s\"\n", num, str);

    return 0;
}

/* 
 * itoa: 整数 n を文字列 s に変換する関数（スライド掲載のコード）
 */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)   /* 負の数かどうを記録しておく */
        n = -n;           /* nをいったん正の数にする */
    
    i = 0;
    do {                  /* 少なくとも1回は必ず実行される（n=0のときのため） */
        s[i++] = n % 10 + '0';   /* 一番下の桁の数字を文字に変換して格納 */
    } while ((n /= 10) > 0);  /* 10で割って次の桁へ（0にならければループ継続） */

    if (sign < 0)
        s[i++] = '-';       /* 負の数だった場合はマイナス記号を追加 */
    
    s[i] = '\0';            /* 文字列の終端マークをつける */
    
    reverse(s);             /* 逆順に格納されているので、正しく直すために反転させる */
}

/* 
 * reverse: 文字列 s の文字の並びを反転させる関数
 */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
