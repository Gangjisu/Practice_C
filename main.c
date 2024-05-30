#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct StudentCard  //구조체 tag
{
    double score; //구조체 member
    char name[30];
    /*
    name 변수 1byte 20개 20 byte인데 구조체 맞춤으로
    가장 많은 바이트 단위로 모든 구조체 맴버의 크기를 통합한다.
    구조체 맴버에 빠르게 접근하기 위해 이러한 형식을 사용한다.
    #pragma pack(바이트단위 크기)로 맞춤단위를 정해줄 수 있다.
    */
    struct StudentCard* pNext;
} SCard;

typedef struct StudentCard_arr  //구조체 tag
{
    double score; //구조체 member
    char name[30];
} SCard_arr;

typedef struct StudentScore  //구조체 tag
{
    double korScore,engScore,mathScore;
} SScore;

typedef struct StudentGrade  //구조체 tag
{
    double totScore;
    char grade;
} SGrade;

typedef struct StudentRecord  //구조체 tag
{
    SScore sScore;
    SGrade sGrade;
    char name[30];

    struct StudentRecord *pNext;
} SRecord;

typedef enum MY_TYPE{SCARD, SRECORD} MyType;

SCard* BuildNode(SCard node)
{
    SCard *pNode = (SCard *)malloc(sizeof node); //동적 할당

    if(pNode != 0)
    {
        strcpy(pNode -> name, node.name);
        pNode->score = node.score;
        pNode->pNext = 0;
    }

    return pNode;
}

typedef enum SORT_ODR{ASC,DESC} SortOdr;
//Visual Studio win OS에서 이미 선언되어있다.

////////////////////////////////
int GetLength2(const SRecord* pHead);
int BubbleSort2(void **ppHead,int num, SortOdr odr,MyType type);
int Swap(SCard **ppNode1,SCard **ppNode2);




//////////////////////////////////////
int FPrintScoreGrade(const char *fName,const SRecord *pHead)
{
    FILE *pFile = 0;

    if(fopen(&pFile,fName)) //오류가능
    {
        printf("File open error...\n"); return -1;
    }

    SRecord *pCur = pHead;

    while (pCur)
    {
        fprintf(pFile,"%18s\t%6.2lf\t%6.2lf\t%6.2lf\t%6.2lf\t%6c \n");
        pCur->name;
        pCur->sScore.korScore;
        pCur->sScore.engScore;
        pCur->sScore.mathScore;

        pCur->sGrade.totScore;
        pCur->sGrade.grade;

        pCur = pCur->pNext;
    }
    fclose(pFile);

    return 0;
}

int JustMark(SRecord **ppRecord, const int num, const char letter)
{
    if(*ppRecord)
    {
        for(int i = 0; i < num; i++)
        {
            (*ppRecord)->sGrade.grade = letter;
            (*ppRecord) = (*ppRecord)->pNext;
        }
    }
    return 0;
}

int MarkGrade(const SRecord* pHead)
{
    SRecord *pCur = pHead;
    //리스트 empty 등 - 예외처리 생략함

    double totNum = GetLength2(pHead);
#define MyRate 0.3
    int As = floor(totNum * MyRate);
    int Bs = floor(totNum * MyRate);
    int Cs = floor(totNum * MyRate);
    int Fs = totNum - (As+ Bs + Cs);

    JustMark(&pCur,As,'A');
    JustMark(&pCur,Bs,'B');
    JustMark(&pCur,Cs,'C');
    JustMark(&pCur,Fs,'F');

    return 0;
}

int BuildGrade(SRecord *pHead)
{
    SRecord *pCur = pHead;
    ///리스트 empty - 예외처리 생략함

    while(pCur)
    {
        pCur->sGrade.totScore = pCur->sScore.korScore +
                                pCur->sScore.engScore + pCur->sScore.mathScore;

        pCur = pCur -> pNext;
    }

    int len = GetLength2(pHead);
    BubbleSort2(&pHead,len,DESC,SRECORD);
    MarkGrade(pHead);

    return 0;
}

SScore  GetAverageScore_fromList(const SRecord* pHead)
{
    SRecord * pCur = pHead;
    //리스트 empty - 예외처리 생략함

    SScore subAveScore = {0.,};
    int listLen = 0;

    while (pCur)
    {
        listLen++;
        subAveScore.korScore += pCur->sScore.korScore;
        subAveScore.engScore += pCur->sScore.engScore;
        subAveScore.mathScore += pCur->sScore.mathScore;

        pCur = pCur->pNext;
    }

    //리스트 길이 0일 때 - 예외처리 생략함
    subAveScore.korScore /= listLen;
    subAveScore.engScore /= listLen;
    subAveScore.mathScore /= listLen;

    return subAveScore;
}

SScore GetMaxScore_fromList(const SRecord *pHead)
{
    SRecord *pCur = pHead;
    //예외처리 생략함

    SScore  subMaxScore = {
            pCur->sScore.korScore,
            pCur->sScore.engScore,
            pCur->sScore.mathScore
    };

    int listLen = 0;

    while (pCur = pCur->pNext)
    {
        if(subMaxScore.korScore < pCur->sScore.korScore)
            subMaxScore.korScore = pCur->sScore.korScore;
        if(subMaxScore.engScore < pCur->sScore.engScore)
            subMaxScore.engScore = pCur->sScore.engScore;
        if(subMaxScore.mathScore < pCur->sScore.mathScore)
            subMaxScore.mathScore = pCur->sScore.mathScore;
    }

    return subMaxScore;
}

SScore GetMinScore_fromList(const SRecord *pHead)
{
    SRecord *pCur = pHead;
    //예외처리 생략함

    SScore  subMinScore = {
            pCur->sScore.korScore,
            pCur->sScore.engScore,
            pCur->sScore.mathScore
    };

    int listLen = 0;

    while (pCur = pCur->pNext)
    {
        if(subMinScore.korScore > pCur->sScore.korScore)
            subMinScore.korScore = pCur->sScore.korScore;
        if(subMinScore.engScore > pCur->sScore.engScore)
            subMinScore.engScore = pCur->sScore.engScore;
        if(subMinScore.mathScore > pCur->sScore.mathScore)
            subMinScore.mathScore = pCur->sScore.mathScore;
    }

    return subMinScore;
}

SCard *BuildNode2(SCard node)
{
    SCard *pNode = (SCard*) malloc(sizeof node);

    if(pNode != 0)
    {
        strcpy(pNode->name,node.name);
        pNode->score = node.score;
        pNode->pNext = 0;
    }

    return pNode;
}

SRecord *BuildRecord(SRecord node)
{
    SRecord *pNode =(SRecord*)malloc(sizeof (SRecord));

    if(pNode != 0)
    {
        *pNode = node;
        pNode->pNext;
    }

    return pNode;
}

int ReleaseList2(SRecord *pHead)
{
    SRecord *pCur = pHead;
    SRecord *pPre = pCur;

    while (pCur != 0)
    {
        pPre = pCur;
        pCur = pCur->pNext;

        free(pPre);
    }

    return 0;
}

int AppendRecord(SRecord **ppHead,SRecord *pNode)
{
    if(!*ppHead)
        *ppHead = pNode;
    else
    {
        SRecord *pCur = *ppHead;
        while (pCur->pNext != 0)
            pCur = pCur->pNext;

        pCur->pNext = pNode;
    }

    return 0;
}

int PrintScoreGrade(const SRecord *pHead)
{
    SRecord *pCur = pHead;

    printf("%16s\t%6s\t%6s\t%6s\t%6s\t%6s\n","Kor","Eng","Mat","Tot","Grd");
    printf("-----------------------------------------\n");

    while (pCur)
    {
        printf("%16s\t%6.2lf\t%6.2lf\t%6.2lf\t%6.2lf\t%6c \n",
               pCur->name,
               pCur->sScore.korScore,
               pCur->sScore.engScore,
               pCur->sScore.mathScore,
               pCur->sGrade.totScore,pCur->sGrade.grade);

        pCur = pCur->pNext;
    }

    return 0;
}

int PrintScore(const SRecord *pHead)
{
    SRecord *pCur = pHead;

    printf("%16s\t%6s\t%6s\t%6s\n","Kor","Eng","Mat");
    printf("-----------------------------------------\n");

    while (pCur)
    {
        printf("%16s\t%6.2lf\t%6.2lf\t%6.2lf \n",
               pCur->name,
               pCur->sScore.korScore,
               pCur->sScore.engScore,
               pCur->sScore.mathScore );

        pCur = pCur->pNext;
    }

    return 0;
}

double CalAveScore(const SCard *pHead)
{
    int totalScore = 0, stuNum = 0;
    SCard *pCur = pHead;

    while (pCur)
    {
        totalScore += pCur->score;
        stuNum++;

        pCur = pCur->pNext;
    }

    return totalScore / stuNum;
}

int GetLength2(const SRecord* pHead)
{
    int len = 0;

    if(pHead)
    {
        SRecord *pCur = pHead;

        while (pCur)
        {
            len++;
            pCur = pCur->pNext;
        }
    }

    return len;
}

int Swap3(SRecord *pNode1, SRecord *pNode2)
{
    SRecord temp = *pNode1;

    pNode1->sScore = pNode2->sScore;
    pNode1->sGrade = pNode2->sGrade;
    strcpy(pNode1->name,pNode2->name);

    strcpy(pNode2->name,temp.name);
    pNode2->sScore = temp.sScore;
    pNode2->sGrade = temp.sGrade;

    return 0;
}

int BubbleSort2(void **ppHead,int num, SortOdr odr,MyType type)
{
    switch (type) {
        case SCARD: {
            SCard *pCur = (SCard *) *ppHead;

            if (!pCur || !pCur->pNext)
                return 0;
            else {
                for (int i = num - 1; i > 0; i--) {
                    pCur = (SCard *) *ppHead;
                    for (int j = 0; j < i; j++) {
                        if (odr == ASC) {
                            if (pCur->score > pCur->pNext->score)
                                Swap(pCur, pCur->pNext);
                        } else {
                            if (pCur->score < pCur->pNext->score)
                                Swap(pCur, pCur->pNext);
                        }

                        pCur = pCur->pNext;
                    }
                }
            }
            break;
        }
        case SRECORD: {
            SRecord *pCur = (SRecord *) *ppHead;

            if (!pCur || !pCur->pNext)
                return 0;
            else {
                for (int i = num - 1; i > 0; i--) {
                    pCur = (SCard *) *ppHead;
                    for (int j = 0; j < i; j++) {
                        if (odr == ASC) {
                            if (pCur->sGrade.totScore > pCur->pNext->sGrade.totScore)
                                Swap3(pCur, pCur->pNext);
                        } else {
                            if (pCur->sGrade.totScore < pCur->pNext->sGrade.totScore)
                                Swap3(pCur, pCur->pNext);
                        }

                        pCur = pCur->pNext;
                    }
                }
            }
            break;
        }
    }
    return 0;
}

int GetStuScore_arr(SCard_arr arr[],int num)
{
    for(int i = 0; i < num; i++)
    {
        printf(">> input score & name(%d persons): ", num);
        scanf("%lf %[^\n]",&arr[i].score, arr[i].name,(unsigned int)sizeof(arr[i].name));
    }

    return 0;
}

int PrintStuCard_arr(const SCard_arr arr[],int num)
{
    for(int i = 0; i < num; i++)
        printf("Name: %s, Score: %.2lf \n",arr[i].name,arr[i].score);

    return 0;
}

double CalcAveScore_arr(const SCard_arr arr[],int num)
{
    double totalScore = 0;

    for (int i = 0; i < num; i++) {
        totalScore += arr[i].score;
    }
    return totalScore / num;
}

int StuNumLess_arr(const SCard_arr arr[],int num, double  score)
{
    int stuNum = 0;

    for (int i = 0; i < num; i++) {
        if(arr[i].score , score)
            stuNum++;
    }

    return  stuNum;
}

/////////////////////////////
//2024 05 29
/////////////////////////////

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

        SCard* pNode = BuildNode2(stuScoreCard);

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
//2024 05 23
//포인터 구조체의 내용은 pNext.score 형태가 아닌 pNext->score 이다.
//insertion 하는 경우에도 3개의 포인터가 필요
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
int GetLength(const SCard *pHead)
{
    int len = 0;

    if(pHead)
    {
        SCard *pCur = pHead;

        while (pCur)
        {
            len++;
            pCur = pCur -> pNext;
        }

    }

    return len;
}

int insertNode(SCard **ppHead, SCard *pNode, int pos)
{
    //위치, buildnode로 노드 하나 새로 만들기, 위치
    //첫번째에 삽입하는 경우 포인터 변수가 바뀌어야 하기 때문에 가장 앞 노드가 넘어와야 한다.
    if(GetLength(*ppHead) < pos -1 || pos < 1)
    {
        printf("error.\n");
        return -1;
    }

    if(!*ppHead)
        *ppHead = pNode;
    else if(pos == 1)
    {
        pNode->pNext = *ppHead;
        *ppHead = pNode;
    }
    else
    {
        SCard* pCur = *ppHead;
        SCard* pPre = pCur;

        for(int i = 1; i < pos; i++)
        {
            pPre = pCur;
            pCur = pCur->pNext;
        }

        pPre->pNext = pNode;
        pNode->pNext = pCur;
    }
}
int Swap(SCard **ppNode1,SCard **ppNode2)
{
    SCard temp = **ppNode1;

    strcpy((*ppNode1)->name,(*ppNode2)->name); // ->가 *보다 우선순위가 높기에 ()처리
    (*ppNode1)->score = (*ppNode2)->score;

    strcpy((*ppNode2)->name,temp.name);
    (*ppNode2)->score = temp.score;

    return 0;
}

int BubbleSort(SCard **ppHead,int num)
{
    SCard *pCur = *ppHead;
    //num = 개수
    if(!pCur || !pCur->pNext)
        return 0;
    else
    {
        for(int i = num - 1; i > 0; i--)
        {
            pCur = *ppHead;
            for(int j = 0; j < i; j++)
            {
                if(pCur->score > pCur->pNext->score)
                {
                    Swap(&pCur,&pCur->pNext);
                }

                pCur = pCur->pNext;
            }
        }
    }

    return 0;
}

//errno_t fopen_s(FILE **f, const char *name, const char *mode) {
//    errno_t ret = 0;
//    assert(f);
//    *f = fopen(name, mode);
//    /* Can't be sure about 1-to-1 mapping of errno and MS' errno_t */
//    if (!*f)
//        ret = errno;
//    return ret;
//}

int main()
{
    FILE * pDataF = 0;
    if(fopen_s(&pDataF, "score.txt", "rt"))
    {
        printf("File open error..."); return -1;
    }

    SRecord  *pListHead = 0;

    char lineStr[100];

    while(fgets(lineStr,sizeof lineStr,pDataF)!= NULL)
    {
        SRecord  node = { {0.,0.,0.},{0.,0},{0,},0};

        sscanf(lineStr, "%lf%lf%lf%[^\n]s",
               &node.sScore.korScore,
               &node.sScore.engScore,
               &node.sScore.mathScore,
               node.name);
        SRecord *pSRecord = BuildRecord(node);
        if(!pSRecord)
        {
            printf("Memory allocation error...\n"); return -1;
        }

        AppendRecord(&pListHead,pSRecord);
    }

    printf("\n>> Student scores from the file: \n");
    PrintScore(pListHead);

    if (!pListHead) return -1;

    ///
    SScore highScores = GetMaxScore_fromList(pListHead);
    SScore lowScores = GetMinScore_fromList(pListHead);
    SScore aveScores = GetAverageScore_fromList(pListHead);

    printf("\n>> Max/Min/Ave score for each subject");
    printf("\nSubject\t Highest Lowest\t Average \n");
    printf("Kor\t %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.korScore,lowScores.korScore,
           aveScores.korScore);
    printf("Eng\t %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.engScore,lowScores.engScore,
           aveScores.engScore);
    printf("Mat\t %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.mathScore,lowScores.mathScore,
           aveScores.mathScore);

    ///
    FILE *pResultTxtF = 0;
    if (fopen_s(&pResultTxtF,"result.txt","wt"))
    {
        printf("File open error... \n"); return -1;
    }

    ///
    fprintf(pResultTxtF," %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.korScore,lowScores.korScore,
           aveScores.korScore);
    fprintf(pResultTxtF," %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.engScore,lowScores.engScore,
           aveScores.engScore);
    fprintf(pResultTxtF," %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.mathScore,lowScores.mathScore,
           aveScores.mathScore);
    fclose(pResultTxtF);

    ///
    FILE *pResultBinF = 0;
    if(fopen_s(&pResultBinF,"result.txt","wb"))
    {
        printf("File open error...\n"); return -1;
    }

    fwrite(&highScores,sizeof highScores,1,pResultBinF);
    fclose(pResultBinF);

    ///
    if(fopen_s(&pResultBinF,"result.bin","rb"))
    {
        printf("File open error...\n");
    }
    fread(&highScores,sizeof highScores, 1, pResultBinF);
    printf("\n>> From the binary file: \n");
    printf("Kor\t %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.korScore,lowScores.korScore,
           aveScores.korScore);
    printf("Eng\t %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.engScore,lowScores.engScore,
           aveScores.engScore);
    printf("Mat\t %6.2lf\t %6.2lf\t %6.2lf\n",
           highScores.mathScore,lowScores.mathScore,
           aveScores.mathScore);

    fclose(pResultBinF);

    /////
    /////
    /////
    BuildGrade(pListHead);

    printf("\n>> Ordered results & grades by total scores: \n");
    PrintScoreGrade(pListHead);

    fclose(pDataF);

    ////
    FPrintScoreGrade("grade.txt",pListHead);

    ////
    ReleaseList2(pListHead);

    //총점이 같은 점수일 때 해당 등급 비율을 늘리고 아래 등급을 줄이기
    //총점이 같은 경우 이름 순으로 (정렬2 함수 변경)

    return 0;
}
