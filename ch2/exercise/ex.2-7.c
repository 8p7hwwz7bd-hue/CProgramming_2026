#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
    // 位置 p から n ビット分が 1 のマスクを作り、XOR (^) で反転させる
    unsigned mask = ~(~0u << n) << (p + 1 - n);
    return x ^ mask;
}

int main(void) {
    unsigned x = 0b11110000; // 240
    
    // 位置 5 から 4ビット分（ビット 2~5）を反転させる
    unsigned result = invert(x, 5, 4);
    printf("Result: 0x%X\n", result);
    return 0;
}
