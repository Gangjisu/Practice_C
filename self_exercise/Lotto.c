#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define lOTTO_CNT 6

enum {AUTO=1, MANUAL}; //AUTO = 1로 열거를 시작하지 않으면 0부터 시작된다.

int GenLotWinNums(int arr[],int cnt) //*arr = arr[]
{
    srand( time(NULL) );
    for(int i = 0; i < cnt; i++)
    {
        arr[i] = rand() % 45 + 1; // 1 ~ 32767
    }

    return 0;
}

int WhichInput()
{
    int input;

    printf("\nWhich input (Auto: 1, Man: 2)? :");
    scanf("%d", &input);

    return input;
}

int GetLottoNums(int user_arr[],int crt,int usr_select)
{
    int input;
    if(usr_select == 2) //직접 선택
    {
        for(int i = 0; i < crt; i++)
        {
            printf("\ninput your 6 number: ");
            user_arr[i] = scanf("%d", &input);
        }
    }
    else //랜덤 
    {
        srand( time(NULL) );
        for(int i = 0;i < crt; i++)
        {
            user_arr[i] = rand() % 45 + 1;
        }
    }

    return 0;
}
int Matching(int winarr[],int usrarr[],int cnt)
{
    printf("correct number: ");
    for(int i = 0; i < cnt; i++)
    {
        for(int j = 0; j < cnt; j++)
        {
            if(winarr[i] == usrarr[j])
            {
                printf("%d ", usrarr[j]);
            }
            else
            {}

        }
    }

    return 0;
}

int main()
{

    int lottoWinNumArr[lOTTO_CNT] = {0,};
    int usrNumArr[lOTTO_CNT] = {0,};

    while (1)
    {
        GenLotWinNums(lottoWinNumArr, lOTTO_CNT); //맞는 로또 번호 생성

        int select = WhichInput();

        if (select != AUTO && select != MANUAL)
        {
            printf("Input Correct num (1 or 2): ");

            continue;
        }

        GetLottoNums(usrNumArr, lOTTO_CNT, select); //내 로또 번호 만들기

        Matching(lottoWinNumArr, usrNumArr, lOTTO_CNT); //로또 번호 확인

        printf("\nAgain? Input 'y' for 'yes', other keys for exit: ");

        rewind(stdin); //입력 버퍼 초기화

        int ch = getchar();

        if (ch != 'y')
        {

            printf("Bye... \n"); break;

        }

        printf("\n");

    }

    return 0;
}