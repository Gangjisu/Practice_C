#include <stdio.h>
#include "Score.h"
//지역변수 포함된 함수가 처음 호출 될때 할당됨, 함수 밖에 나가면 없어짐
//전역변수 동일한 파일내에서 사용가능, 파일 외부에서 사용가능, 프로그램이 처음 시작할 때 할당됨,
//프로그램의 종료 직전에 없어짐,전역변수는 자동으로 초기화 된다. 
//숫자형 변수는 0.0 또는 0, 문자형은 0으로 각 타입의 디폴트 값으로 변경됨.
//정적 전역 변수는 파일내에서만 사용가능
//여러개의 파일로 나뉘어져 있을 경우 분할 컴파일링이 필요하다.
//컴파일 언어 단점은 기능을 파일로 나누어서 완화할 수 있다.
extern double scoreArr[]; //외부에서 것을 참조할 때 사용된다.
extern int arrSize;

int main()
{
    GetScores(scoreArr, arrSize);

    double aveScore = GetAverageScore(scoreArr, arrSize);
    double maxScore = GetMaxScore(scoreArr, arrSize);
    double minScore = GetMinScore(scoreArr, arrSize);

    printf("Average score: %.1lf \n Max score: %.1lf \n Min score: %.1lf\n", aveScore, maxScore, minScore);

    return 0;
}