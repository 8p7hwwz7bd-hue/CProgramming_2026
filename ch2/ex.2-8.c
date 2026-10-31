#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    int wordsize = sizeof(unsigned) * 8; // unsigned 型のビット幅（通常32ビット）
    n = n % wordsize; // n がビット幅を超えた場合の補正

    if (n == 0) {
        return x;
    }

    // 右シフトされた部分と、あふれて左端に回り込む部分を結合
    return (x >> n) | (x << (wordsize - n));
}

int main(void) {
    unsigned x = 0b00000000000000000000000000000101u; // 5
    
    // 右に 2 ビット循環シフト
    unsigned result = rightrot(x, 2);
    printf("Result: 0x%X\n", result);
    return 0;
}
