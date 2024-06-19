#include <stdio.h>
#include <math.h>
#define ARR_NUM 100

int isTheDivisor(int candidateNum, int num)
{
    return !(num % candidateNum);
}

int GetDivisors(int divisors[], int num)
{
    for( int i = 1, index = 0; i <= num; i++)
    {
        if(isTheDivisor(i, num))
            divisors[index++] =i;
    }

    return 0;
}

int GetDivisors2(int divisors[], int num, int arrSize)
{
    double rootNum = sqrt(num);

    int existCenterNum = (fmod(num, rootNum) > 0.) ? 0 : 1;

    switch (existCenterNum) {

        case 0:
            for(int leadNum = 1, idxFront = 0, idxBack = arrSize - 1; leadNum <= sqrt(num); num++)
            {
                int trailNum;
                if(num % leadNum == 0)
                {
                    trailNum = num / leadNum;

                    divisors[idxFront++] = leadNum; //-->
                    divisors[idxBack--] = trailNum; //<--
                }    
            }
            break;
        case 1: 
            for( int leadNum = 1, idxFront = 0, idxBack = arrSize - 1; leadNum <= sqrt(num); leadNum++)
            {
                int trailNum;
                if(num % leadNum == 0)
                {
                    trailNum = num / leadNum;

                    divisors[idxFront++] = leadNum;
                    if(leadNum != trailNum)
                        divisors[idxBack--] = trailNum;
                }
            }
            break;
    }
    return 0;
}

void PrintNumBefore0(int arr[], int num)
{
    for(int i = 0; (arr[i] != 0) && (i < num); i++)
        printf("%d", arr[i]);
}

void PrintNumNot0(int arr[], int num)
{
    for(int i = 0; i < num; i++)
    {
        if(arr[i])
            printf("%d", arr[i]);
    }
}

int main()
{
    int num;

    while (1)
    {
        printf("input number: ");
        if (scanf("%d", &num) == EOF || num == 0) {
            break;
        }

        //1 약수들을 출력만 하기
        for(int i = 1; i <= num; i++)
        {
            if(num % i == 0)
                printf("%d ", i);
        }

        printf("\n");

        //2 약수들을 배열에 보관 후 출력하기
        int divisorArr[ARR_NUM] = { 0, };
        GetDivisors(divisorArr, num);
        PrintNumBefore0(divisorArr, ARR_NUM);
        printf("\n");

        //3 비교 회수 줄이기
        int divisorArr2[ARR_NUM] = { 0, };
        GetDivisors2(divisorArr2, num, ARR_NUM);
        PrintNumNOT0(divisorArr2, ARR_NUM);
        printf("\n");

    }

    return 0;
}