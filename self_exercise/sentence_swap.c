#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void swap(char **args_1, char **args_2)//더블 포인터
void swap(char (*args_1)[], char (*args_2)[]) //배열 포인터
{
    int bigrStrLen = (strlen(*args_1) > strlen(*args_2)) ? strlen(*args_1) : strlen(*args_2);
    char *temp = (char *)malloc(bigrStrLen + 1); //길이만큼 할당 malloc(size_t size);
    //길이가 50으로 정해저 있지 않다는 가정으로 만든 것.

    strcpy(temp,*args_1);
    strcpy(*args_1,*args_2);
    strcpy(*args_2,temp);
}//포인터 안의 주소를 바꾸어 내용물을 바꾼다고 생각하자


int main()
{
    char sentences[][3][50] ={ { "Chul-su", "likes", "a strawberry juice." } //배열에서 하나는 생략가능하다.
    ,{ "Young-hee", "likes", "a watermelon smoothie." } }; // [행]row [열]col [면]slice(field)
    //[1][3][50] = 150 [1][3][50] = 150 
    //arr[0] = *pointer arr[1] = *(pointer + 1) arr[1][1] = *(*pointer); arr[1][2] = *(*(pointer + 1))
    //2x3x50

    char *pStr1 = sentences[0][2];
    char *pStr2 = sentences[1][2];
    
    printf("Before:%s %s %s", sentences[0][0], sentences[0][1], sentences[0][2]);
    printf("\nBefore:%s %s %s", sentences[1][0], sentences[1][1], sentences[1][2]);
    // swap(&pStr1, &pStr2); //포인터 주소 더블 포인터로 받아야 경고가 발생하지 않는다.
    swap(&sentences[0][2],&sentences[1][2]); //배열주소  배열포인터로 받아야 경고가 발생하지 않는다.
    printf("\nAfter:%s %s %s", sentences[0][0], sentences[0][1], sentences[0][2]);
    printf("\nAfter:%s %s %s", sentences[1][0], sentences[1][1], sentences[1][2]);


    return 0;
}