#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* TrimLeft(const char* pStr)
{
    char *pPos = &pStr;
    if(!*pStr)
    {
        return 0;
    }
    while (*pPos == ' ')
    {
        pPos++;
    }

    return 0;
}

char* my_strtok(char *ori_str,char **next_str)
{//원본 받아오기,static으로 함수안에 원본 유지
    static char* target_arr = 0;
    char *pToken = 0, *pCur = 0;

    if( target_arr == 0)
    {
        int allocSize = sizeof(char) * strlen(ori_str) + 1;
        target_arr = malloc(allocSize);

        strcpy(target_arr, allocSize, ori_str); //strcpy_s 필요

        pCur = pToken = TrimLeft(target_arr); //공백 다음 주소 전달
    }
    else if (**next_str == 0)
    {
        free(target_arr);
        pCur = pToken = 0;
    }
    else
        pCur = pToken = TrimLeft(*next_str); //공백 다음 주소 전달
    
    while (pCur && *pCur != 0)
    {
        if (*pCur == ' ') //단어 구분자
        {
            *pCur = 0; //단어 끝에 널을 넣어서 단어 문자열 완성
            ++pCur;

            break;
        }
        else
            ++pCur;

    }

    *next_str  = pCur;
    
    
    return pToken;
}

int main()
{//문제의 그림만 보고 구현 연습
        
    char article[] = " hello world "; // 공백 개수/위치 등 여러 문자열 형태를 테스트할 것

    // printf("input your string: ");
    // scanf("%s", articale);

    int input = 0;

    printf("Input (strtok: 0, my_strtok: 1): ");//선택

    scanf("%d", &input);

    printf("Source string: %s \n", article);

    if(input == 0)
    {
        const char* delim = " ,\t.?";

        char* next_token = 0;

        char* token = strtok_r(article, delim, &next_token); // 번지 연산자
        //원본 문자열 포인터, 구분점,

        while(token)
        {

            printf("Token: %s, \t", token);

            printf("Remained str: %s \n", next_token);

            token = strtok_r(NULL, delim, &next_token);// NULL일 경우, 이전 나머지 문자열을대상으로 계속

            // 내부적으로 static 변수를 통해 문자열을 유지

            // 이 NULL 인자 구문을 삭제하고 주석처리한 구문으로 대체해도 된다.

            //Next = next_token;

            //token = strtok_s(Next, delim, &next_token);

        }
    }

    else
    {
        char *pNext = 0;
        char *pToken = my_strtok(article, &pNext);

        while (pToken && *pToken)//토큰이 널 포인터인지, 널 문자인지 두 경우 모두 체크해야 함.
        {//어디든 널이면 추출을 중지해야 한다.
            printf("Token: %s \t", pToken);
            printf("Remained str: %s \n", pNext);

            pToken = my_strtok(0,&pNext);
        }
        
    }
    return 0;
}