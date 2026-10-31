#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("=== From Standard Headers ===\n");
    printf("Signed char  : %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 ~ %u\n", UCHAR_MAX);
    printf("Signed short : %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0 ~ %u\n", USHRT_MAX);
    printf("Signed int   : %d ~ %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int : 0 ~ %u\n", UINT_MAX);
    printf("Signed long  : %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 ~ %lu\n", ULONG_MAX);
    printf("Float        : %e ~ %e\n", FLT_MIN, FLT_MAX);
    printf("Double       : %e ~ %e\n", DBL_MIN, DBL_MAX);

    printf("\n=== From Direct Computation ===\n");
    printf("Unsigned char max: %u\n", (unsigned char)~0);
    printf("Signed char max  : %d\n", (char)((unsigned char)~0 >> 1));
    printf("Signed char min  : %d\n", -(char)((unsigned char)~0 >> 1) - 1);
    
    printf("Unsigned int max : %u\n", (unsigned int)~0);
    printf("Signed int max   : %d\n", (int)((unsigned int)~0 >> 1));
    printf("Signed int min   : %d\n", -(int)((unsigned int)~0 >> 1) - 1);

    return 0;
}
