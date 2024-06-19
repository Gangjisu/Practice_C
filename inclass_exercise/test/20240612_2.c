#include <stdio.h>

int main()
{
    //1 2 4 7 11 16
    //////////////// 시험
    //항목 간의 차이가 자연수
    //3개의 제어 변수를 도입
    // N 번째까지 회차를 증가시켜 저장할 변수
    // i 번째 항목 값을 저장하는 변수
    // 항목 사이의 증분 값을 저장할 변수
    int N;
    int fac_sum = 0;
    int factorial = 0;

    while (1){
        printf("input N:");

        if (scanf("%d", &N) == EOF) {
            break;
        }

        printf("%d!: ", N);

        for (int i = 1; i <= N; i++) {
            printf("%d! + ", i);

            for (int j = 1; j <= i; j++) {
                factorial *= j;
            }
            fac_sum += factorial;
            factorial = 1;
        }

        printf("\b\b= %d \n", fac_sum); //\b = backspace 끝에 지우고

        fac_sum = 0;
    }
    return  0;
}


