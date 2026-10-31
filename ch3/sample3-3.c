#include <stdio.h>

// プロトタイプ宣言
int binary(int x, int v[], int n);

int main(void)
{
    // ソート済みの配列（必ず小さい順に並んでいる必要があります）
    int v[] = {1, 2, 5, 6, 7, 9, 11, 13};
    int n = 8; // 配列の要素数
    int target = 9; // 探したい値

    printf("=== Binary Search Example ===\n");
    printf("Searching for %d in the array...\n", target);

    // binary関数を呼び出す
    int index = binary(target, v, n);

    if (index != -1) {
        printf("Found! The value %d is at index %d.\n", target, index);
    } else {
        printf("Not found.\n");
    }

    return 0;
}

/* 
 * binary: v[0] <= v[1] <= ... <= v[n-1] の中から x を見つける関数
 * 見つかった場合はそのインデックス（位置）を返し、見つからない場合は -1 を返す
 */
int binary(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    
    while (low <= high) {
        // 真ん中の位置（インデックス）を計算する
        mid = (low + high) / 2;
        
        // 1. 探したい値が真ん中より小さい場合 → 探索範囲を左半分に絞る
        if (x < v[mid]) {
            high = mid - 1;
        } 
        // 2. 探したい値が真ん中より大きい場合 → 探索範囲を右半分に絞る
        else if (x > v[mid]) {
            low = mid + 1;
        } 
        // 3. どちらでもない場合 → 一致（見つかった！）
        else {
            return mid;  /* found match */
        }
    }
    
    return -1; // 見つからなかった場合
}