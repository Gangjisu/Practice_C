#include <stdio.h>

void swap(char **args_1, char **args_2)//Hello <- *p1  &p1 <- **args_1
{
    char *temp;
    temp = *args_1; //*p1 <- *temp
    *args_1 = *args_2;
    *args_2 = temp;

}

int main()
{
    char *p1 = "Hello";
    char *p2 = "World";

    printf("Before:\np1:%s, p2:%s", p1, p2);
    swap(&p1, &p2);
    printf("\nAfter:\np1:%s, p2:%s", p1, p2);
    
    return 0;
}