#include <stdio.h>
#include <stdlib.h> // malloc, calloc, free を使うために必要

int main(void)
{
    printf("=== Dynamic Memory Allocation Test ===\n");

    int *arr_1;
    int *arr_2;

    /* 
     * malloc のテスト: 
     * 指定したバイト数のメモリを確保する（中身は初期化されない）
     */
    arr_1 = (int *)malloc(sizeof(int) * 4);

    /* 
     * calloc のテスト: 
     * 「要素数」と「個々のサイズ」を指定して確保し、中身をすべて 0 で初期化する
     */
    arr_2 = (int *)calloc(4, sizeof(int));

    if (arr_1 == NULL || arr_2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 値を代入して確認
    for (int i = 0; i < 4; i++) {
        arr_1[i] = i + 1;
        printf("arr_1[%d] = %d | arr_2[%d] = %d (calloc initializes to 0)\n", 
               i, arr_1[i], i, arr_2[i]);
    }

    /* 
     * free のテスト: 
     * 動的に確保したメモリは、使い終わったら必ず free で解放する
     */
    free(arr_1);
    free(arr_2);

    printf("\nDynamic memory successfully freed using free().\n");

    return 0;
}