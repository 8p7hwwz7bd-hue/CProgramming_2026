#include <stdio.h>

#define ALLOCSIZE 10000     /* 利用可能なストレージのサイズ */

static char allocbuf[ALLOCSIZE];    /* alloc 用のストレージ */
static char *allocp = allocbuf;     /* 次の空き要素を指すポインタ */

/* 確保した領域へのポインタを返す */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* 格納スペースがあるかチェック */
        allocp += n;
        return allocp - n; /* 割り当てた領域の先頭を返す */
    } else {
        return 0; /* 領域不足（エラー） */
    }
}

/* p が指す位置までストレージを解放する */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int main(void)
{
    printf("=== Static Memory Allocation Test ===\n");

    // alloc を使ってメモリ（領域）を確保してみる
    char *p1 = alloc(100);
    if (p1 != NULL) {
        printf("Successfully allocated 100 bytes statically.\n");
    }

    // 使い終わったら afree で解放する
    afree(p1);
    printf("Memory freed using afree.\n");

    return 0;
}
