#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct StudentCard  //구조체 tag
{
    double score; //구조체 member
    char name[20];
    /*
    name 변수 1byte 20개 20 byte인데 구조체 맞춤으로
    가장 많은 바이트 단위로 모든 구조체 맴버의 크기를 통합한다.
    구조체 맴버에 빠르게 접근하기 위해 이러한 형식을 사용한다.
    #pragma pack(바이트단위 크기)로 맞춤단위를 정해줄 수 있다.
    */
    struct StudentCard* pNext;
} SCard;

SCard* BuildNode(SCard node)
{
    SCard *pNode = (SCard *)malloc(sizeof node);

    if(pNode != 0)
    {
        strcpy(pNode -> name, node.name);
        pNode->score = node.score;
        pNode->pNext = 0;
    }

    return pNode;
}
//Visual Studio에서 이미 선언되어있다.

int ReleaseList(SCard *pHead)
{
    SCard* pCurNode = pHead;
    SCard* pPreNode = pCurNode;

    while (pCurNode != 0)
    {
        pPreNode = pCurNode;
        pCurNode = pCurNode -> pNext;

        free(pPreNode);
    }

    return 0;
}

int Append(SCard **ppHead, SCard *pNode)
{
    if(!*ppHead)
    {
        *ppHead = pNode;
    }
    else
    {
        SCard *pCur = *ppHead;
        while (pCur->pNext != 0)
        {
            pCur = pCur->pNext;
        }

        pCur->pNext = pNode;
    }

    return 0;
}

int GetStuScore(SCard **ppHead)
{
    SCard stuScoreCard;
    char quitinput[2];

    while (1)
    {
        printf("input score & name(Stop:'q' or ^Z): ");

        int rV = scanf("%lf %[^\n]", &stuScoreCard.score, stuScoreCard.name);

        if(rV == EOF)
            break;

        if(fgets(quitinput, sizeof quitinput, stdin) != NULL && quitinput[0] == 'q') //input stop method 2
            break;

        SCard* pNode = BuildNode(stuScoreCard);

        if(!pNode)
        {
            printf("Memory allocation error...\n");
            return -2;
        }

        if(!*ppHead)
            *ppHead = pNode;
        else
            Append(ppHead, pNode);
    }

    return 0;
}

int PrintStuCard(const SCard *pHead)
{
    SCard *pCur = pHead;

    while (pCur)
    {
        printf("Name: %s, Score: %.2lf \n", pCur->name,pCur->score);
        pCur = pCur->pNext;
    }

    return 0;
}

double CalcAveScore(const SCard *pHead)
{
    int totalScore = 0,stuNum = 0;
    SCard *pCur = pHead;

    while (pCur)
    {
        totalScore += pCur -> score;
        stuNum++;

        pCur = pCur -> pNext;
    }

    if(!stuNum)
    {
        printf("# of Student is ZERO. \n");
        return -1;
    }

    return totalScore / stuNum;
}

int StuNumLess(const SCard *pHead, double score)
{
    int stuNum = 0;
    SCard *pCur = pHead;

    while (pCur)
    {
        if(pCur->score < score)
        {
            stuNum++;
        }

        pCur = pCur->pNext;
    }
    return stuNum;
}

/////////////////////////////////
//2024 05 22
//포인터 구조체의 내용은 pNext.score 형태가 아닌 pNext->score 이다.
/////////////////////////////////

int DeleteNode(SCard **ppHead, const char* pName)
{
    //링크를 1-2-3 을 1-3으로 바꿔주고
    //그리고 2번 노드를 삭제, 마지막 노드의 pNext는 null를 가르키도록 해야한다
    SCard *pCur = *ppHead; //current
    SCard *pPre = 0; //same with temp //pre 이전
    //노드 조사 이후 free 할때에만 3개의 포인터가 필요해서 사용됨

    if(pCur)
    {
        if(strcmp( pCur->name, pName) == 0)
        {
            if(!pCur->pNext)//do not have next node // number of node is 1
            {
                free(pCur);
                *ppHead = 0; //최고 노드 초기화

                return 0;
            }
            else
            {
                pPre = pCur;
                *ppHead = pCur->pNext;

                free(pPre);

                return 0;
            }
        }
    }

    //more than two nodes
    while (pCur)
    {
        if(strcmp( pCur->name, pName) == 0)//if same name with target
        {
            pPre->pNext = pCur->pNext;
            free(pCur);

            break;
        }
        else
        {
            pPre = pCur;
            pCur = pCur->pNext;
        }
    }
    //마치 swap 함수처럼 작동하고 있음
    return 0;
}

int main()
{
    SCard* pListHead = 0;
    GetStuScore(&pListHead);

    if(pListHead) //리스트가 빌 수 있음
    {
        printf("\n>> Students in the list: \n");
        PrintStuCard(pListHead);

        char name[30] = {0,};
        printf("\n>> input name to delete: ");
        rewind(stdin);
        gets(name);

        DeleteNode(&pListHead, name);
        //헤드 노드가 삭제될 경우일때 헤드가 변화해야 되기 때문이다.

        printf("\n>> Students in the list: \n");
        PrintStuCard(pListHead);

        ReleaseList(pListHead);
    }

    return 0;
}