#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // x の対象ビットをマスクしてクリアし、y の右端 n ビットを p の位置にシフトして結合する
    unsigned mask = ~(~0u << n);
    return (x & ~(mask << (p + 1 - n))) | ((y & mask) << (p + 1 - n));
}

int main(void) {
    unsigned x = 0b11111111; // 255
    unsigned y = 0b00000101; // 5 (最右3ビット: 101)
    
    // x の位置 4 から 3ビット分を y の最右3ビット(101)に置き換える
    unsigned result = setbits(x, 4, 3, y);
    printf("Result: 0x%X\n", result);
    return 0;
}
