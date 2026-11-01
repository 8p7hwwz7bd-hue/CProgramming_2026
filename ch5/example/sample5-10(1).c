#include <stdio.h>

/* 
 * echo command-line arguments: 1st version
 * argc: 引数の個数（argument count）
 * argv: 引数の文字列の配列（argument vector）
 */
int main(int argc, char *argv[])
{
    int i;

    // argv[0] はプログラム自身の名前が入るため、引数は argv[1] から始まる
    for (i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");

    return 0;
}
