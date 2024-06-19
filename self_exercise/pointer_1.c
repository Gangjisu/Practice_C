#include <stdio.h>
#include <string.h>

int main()
{
    char input[100] = {0,};
    char cpyarr[100] = {0,};
    int count = 0;
    char *changer;

    printf("input:");
    scanf("%[^\n]s", input); //개행문자 입력시까지 입력받기
    printf("input string:%s\n", input);

    for(int i= 0; i < sizeof(cpyarr); i++)
    {
        changer = &cpyarr[i]; 
        if(91 > *changer && *changer > 64)//대문자 
        {
            *changer += 32;  //소문자로 변경 
        }
        else if(*changer == 32)//space 입력
        {
            count++;
        }
        else if(123 > *changer && *changer > 96 )//소문자
        {
            *changer -= 32; //대문자로 변경
        }
        
    }
    printf("After:%s\nSpace count:%d", cpyarr, count);
    //대문자 +32 -> 소문자

    return 0;
}