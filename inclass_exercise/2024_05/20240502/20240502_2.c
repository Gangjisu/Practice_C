#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PERSONS 3
#define STR_LEN 50

//void GetNames(char(*names)[STR_LEN],int personNum)
// changeNames에서는 복사본을 만들어서 수정후 따로 저장

int main()
{
    char personNames[PERSONS][STR_LEN] = { 0,};

    printf("%d명 의 이름 입력: \n", PERSONS);
    for (int = 0; i < PERSONS; i++)
        scanf(" %[^\n]s", personNames[i], sizeof(personNames[i]));

    //
    int longestLen = 0;
    char *pLongestName = 0;
    
    for(int i = 0; i < PERSONS; i++)
    {
        int nameLen = strlen(personNames[i]);
        
        if(nameLen > pLongestName)
        {
            longestLen = nameLen;
            pLongestName = personNames[i];
        }

        for(int j = 0; j < nameLen; j++)
            if(isupper(personNames[i][j]))
                personNames[i][j] = tolower(personNames[i][j]);
            else
                personNames[i][j] = toupper(personNames[i][j]);
        
    }

    printf("\n수정된 이름: \n");
    for(int i = 0; i < PERSONS; i++)
        printf("%s \n",personNames[i]);
    
    printf("가장 긴 이름(길이: %s(%d자)(공백포함) \n",pLongestName, longestLen);

    return 0;
}