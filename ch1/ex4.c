#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower = 0, upper = 150, step = 10;

    printf("Celsius  Fahr\n");
    printf("-------------\n");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (celsius * 9.0 / 5.0) + 32.0;
        printf("%6.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
