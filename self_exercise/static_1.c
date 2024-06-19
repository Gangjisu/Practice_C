#include <stdio.h>

void MyFunc(int m,int n)
{   
    
}

int main()
{
    int M,N;
    
    printf("두 정수를 입력하시오.(예: 5 11):");
    int reV = scanf_s("%d %d", &M, &N);

    if(reV == 2)
    {
        int cnt = (M - n >= 0) ? (M-N+1) : -(M-N-1);
        if(M < N)
            while (cnt--)
            {
                MyFunc(M,N); //ascending
            }
        else if(M > N)
            while (cnt--)
            {
                MyFunc(M,N); //decending
            }
        else
            printf("error! \n");
            
            
    }

    printf("\n");
    return 0;
}