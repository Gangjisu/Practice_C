#include <stdio.h>
#include "Score.h"
//임플리맨테이션 부분, 함수의 바디부분
#define N 5 //매크로 상수라서 값으로 줄 수 있다


double scoreArr[N];
int arrSize = N;


int GetScores(double score_Arr[],int arr_Size)
{
    printf("Input your scores : ");
    
    for(int i = 0; i < arr_Size; i++)
    {
        scanf("%lf", &score_Arr[i]);
    }
    return 0;
}

double GetAverageScore(const double score_Arr[],int arr_Size)
{   
    double score = 0;

    for(int i = 0; i < arr_Size; i++)
    {
        score += score_Arr[i];
    }

    return (score = score / arr_Size);
}

double GetMaxScore(const double score_Arr[],int arr_Size)
{
    double score = 0;

    for(int i = 0; i < arr_Size; i++)
        if(score < score_Arr[i])
            score = score_Arr[i];

    return score;
}

double GetMinScore(const double score_Arr[],int arr_Size)
{
    double score = score_Arr[0];

    for(int i = 0; i < arr_Size; i++)
    {    
        if(score > score_Arr[i])
        {
            score = score_Arr[i];
        }
    }
    return score;
}