#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void swap(char (*args_1)[], char (*args_2)[])
{
    char *temp = (char *)malloc(50);
    strcpy(temp,*args_1);
    strcpy(*args_1,*args_2);
    strcpy(*args_2,temp);
}

int main()
{
    int num_voca = 0;//입력받을 문자 개수

    printf("\n입력:");
    scanf("%d", &num_voca);
    char voca_array[20000][50] ={{'0',}};

    //입력
    for(int i = 0; i < num_voca; i++)
    {
        printf("\n입력:");
        scanf("%s", voca_array[i]);//문자입력
    }

    //sorting
    for(int i = 0; i < num_voca; i++)
    {
        for(int j = 0; j < num_voca; j++)
        {

            if(strlen(voca_array[i]) < strlen(voca_array[j])) //길이순
            {
                swap(&voca_array[i],&voca_array[j]);
            }
            else if(strlen(voca_array[i]) == strlen(voca_array[j]) && voca_array[i] > voca_array[j]) //사전순
            {
                swap(&voca_array[i],&voca_array[j]);
            }
            else{}
            
        }
    }
    
    //duplicate 넣어진 배열에서 빼는 것은 어렵기에 처음부터 중복체크해서 넣어주기
    char *emptyArr = "\0";
    for(int i = 0; i < num_voca; i++)//중복 제거
    {
        for(int j = 0; j < num_voca; j++)
        {
            if(strcmp(voca_array[i],voca_array[j]) == 0 && strcmp(voca_array[i],emptyArr) != 0)
            {
                strcpy(voca_array[i],emptyArr);//    
            }
        }
    }

    //출력
    for(int a = 0; a < num_voca; a++)
    {
        printf("\n%s", voca_array[a]);
    }

    return 0;
}