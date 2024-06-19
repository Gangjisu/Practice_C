#include <stdio.h>

int main()
{
    int score;
    
    printf("score:");
    scanf("%d", &score);

    if(score >= 90 && score =< 100)
    {
        printf("\nA");
    }
    else if(score >= 80)
    {
        printf("\nB");
    }
    else if(score >= 70)
    {
        printf("\nC");
    }
    else if(score >= 60)
    {
        printf("\nD");
    }
    else if(score < 60 && score >= 0)
    {
        printf("\nF");
    }
    else 
    {
        printf("\nWrong input");
    }

    return 0;
}