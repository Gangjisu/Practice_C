#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// copy  src.bmp  tgt.bmp

int  main()//(int  argc, char* argv[]) //명령행 인자로 값 넘겨주기
{

    FILE* pSrc = 0, * pTgt = 0;
    //printf("Copy: %s --> %s \n", argv[1], argv[2]);

    int  reV1 = fopen("AudreyHepburn.bmp", "rb"); //_s(&pSrc)
    int  reV2 = fopen("AudreyHepburn.bmp", "rb"); //_s(*pTgt)

    if (reV1 || reV2)
    {
        printf("File open error ... \n");
        exit(0);
    }
    /// Start copying ...

    /// fseek, ftell, 
    //바이너리를 사용할때에는 fread, fwrite 등 적절히 사용

    clock_t start = clock();

    double data[128]; 이러식으로 복사하는 단위를 늘리고 파일의 크기에서 나누면 몫만큼 큰 단위로 복사하고, 나머지만큼 작은 단위로 복사한다.

    fseek(pSrc, 0, SEEK_END);
    int fSize = ftell(pSrc);
    int iterCnt = fSize / sizeof ch; //몫

    while (fread(&data, sizeof data, 1, pSrc) != 0) //파일의 끝에는 항상 EOF 0이 있기에 파일의 끝까지 계속 반복
        fwrite(&data, sizeof data, 1, pSrc); //바이트 단위가 아닌 단위로 최대한 읽고 자투리는 바이트로 처리. 
    char ch;
    while (fread(&ch, sizeof ch, 1, pSrc) != 0) //파일의 끝에는 항상 EOF 0이 있기에 파일의 끝까지 계속 반복
        fwrite(&ch, sizeof ch, 1, pSrc); //바이트 단위가 아닌 단위로 최대한 읽고 자투리는 바이트로 처리. 


    clock_t end = clock();
    printf("Elapsed time: %lf\n", (double)(end - start) / 1000);

    fclose(pSrc); //항상 해줘야한다.
    fclose(pTgt);

    return  0;
}

