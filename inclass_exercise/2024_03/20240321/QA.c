#include <stdio.h>
#include <math.h>

int main()
{
    long long int num = 59;
 
    for (int i = 31; i >= 0; i--)
    {
        long long int mask = (long long int) pow(2, i);
        int bit = (num & mask) ? 1 : 0;
 
        printf("%d", bit);
    }
    return 0;
}