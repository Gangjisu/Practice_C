/*
    2024.03.21 thu 08:56
*/
#include <stdio.h>

int main()
{
    long long int number = 59;
    
    printf("%lld", (number >> 63) & 1);
    printf("%lld", (number >> 62) & 1);
    printf("%lld", (number >> 61) & 1);
    printf("...");
    printf("%lld", (number >> 7) & 1);
    printf("%lld", (number >> 6) & 1);
    printf("%lld", (number >> 5) & 1);
    printf("%lld", (number >> 4) & 1);
    printf("%lld", (number >> 3) & 1);
    printf("%lld", (number >> 2) & 1);
    printf("%lld", (number >> 1) & 1);
    printf("%lld", (number >> 0) & 1);

    return 0;
}