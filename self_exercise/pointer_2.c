#include <stdio.h>

int main()
{
    int case_count = 0;
    printf("number of test case:");
    scanf("%d",&case_count);

    for(int i = 0; i < case_count; i++)//test case 반복횟수
    {
        int addpoint = 1;
        int total_point = 0;
        char case_input[80] = {' ',};

        printf("case %d:",i);
        scanf("%s", case_input);

        for(int j = 0; j < 80; j++)
        {
            if(case_input[j] == 'O')//O
            {   
                total_point += addpoint;
                addpoint++;
            }
            else if(case_input[j] == 'X')//X 
            {
                addpoint = 1;
            }
            else
            {}
        }
        printf("totalpoint: %d\n", total_point);
    }

    return 0;
}