#include <stdio.h>

void MyFunc(int m,int n)//함수의 선언
{   //함수의 정의
    static int num;

    if(num == 0)
    {
        num = m;
    }
    if(m < n)//삼항연사자 이용가능
    {
        printf("%d\t", num);
        num++;
    }
    else
    {
        printf("%d\t", num);
        num--;
    }
        
}

int main()
{
    int M,N;
    
    printf("두 정수를 입력하시오.(예: 5 11):");
    int reV = scanf("%d %d", &M, &N);

    if(reV == 2)
    {
        int cnt = (M - N >= 0) ? (M-N+1) : -(M-N-1);
            while (cnt--)
            {
                MyFunc(M,N); //ascending / decending
            }           
    }

    printf("\n");
    return 0;
}