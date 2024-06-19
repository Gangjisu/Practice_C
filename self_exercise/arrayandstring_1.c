//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int  main()
{
    char srcStr[100] = {0,};

    printf("Input your strings(less than 100 chars): ");
    scanf("%[^\n]s", srcStr); //, sizeof(srcStr) 이거 뭐지
    
    
    const char* curChar = srcStr;

    int alphaCnt[52] = { 0, }; // A: [0] ~ Z: [25], a: [26] ~ z: [51]
    char  ch;   

    while (*curChar != '\0')
    {
        // 문자열에 포함된 각 알파벳(대소문자 구분)을 배열의 해당 인덱스에 누적시키는 코드 
        // 대문자(65 ~ 90)와 소문자(97 ~ 122)일때만 배열에 누적 시킬 것 
        // 참고: ASCII codes: A - 65, Z - 90, a - 97, z - 122
        if(*curChar >= 65 && *curChar <= 90) 
        {
            alphaCnt[*curChar - 65] += 1;
        }
        else if(*curChar >= 97 && *curChar <= 122)
        {
            alphaCnt[*curChar - 71] += 1;
        }

        curChar++;
    }

    printf("Original string: %s \n", srcStr);

    for (int i = 0; i < 52; i++)
    {    // 배열의 현재 카운트 값을 참고하여 0이 아닌 알파벳에 대해서만 출현 회수를 출력
        if (alphaCnt[i] != 0)
        {
            if (i <= 25) // 대문자 출력
            {                //108
                printf("\n%c: %d",(i + 65),alphaCnt[i]);
            }
            else // 소문자 출력
            {   
                printf("\n%c: %d",(i + 71),alphaCnt[i]);
            }
        }
    }
    return 0;
}
