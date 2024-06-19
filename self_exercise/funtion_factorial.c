#include <stdio.h>

void factorial() //팩토리얼 출력함수
{
    int num;
    long long storage = num;

    printf("!number:");
    scanf("%d", &num);
    if(num != 0)
    {
        for(int i = num; i > 0; i--)
        {
            storage = storage * i;
        }
        printf("!%d = %lld\n",num, storage);
        factorial();
    }
    else{}
}

void fibonacci()
{
    int n_1 = 1;
    int n_2 = 1;
    int n_f, num;

    printf("fibonacci nst term:");
    scanf("%d", &num);
    if(num != 0)
    {
        if(num > 2)
        {
            for(int i = 0; i < num - 2; i++)
            {
                n_f = n_1 + n_2;
                n_1 = n_2;
                n_2 = n_f;
            }
            printf("fibonacci # of %d th: %d\n", num, n_f);
        }
        else
        {
            printf("Must be greater than 3. input again...\n");
        }
        fibonacci();
    }
    else{}
}

int main()
{
    factorial(); //함수 호출
    fibonacci();

    return 0;
}