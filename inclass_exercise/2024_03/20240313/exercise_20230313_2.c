#include <stdio.h>

int main()
{
    int age = 0;
    float num = 3.14;  //float에 double 값을 넣은 꼴이다. postfix로 f를 붙여줘야한다. type casting or conversion 묵시적 형변환이 일어나 오류가 발생하지는 않는다.

    printf("%s","MY information:\n");
    printf("\t이름: 홍 길동");
    printf("\n\t나이: %d\n", 20);
    printf("\t키: %.1f\n\t", 188.5f); //postfix f가 없기에 기본자료형 double형 이다.
    printf("성별: %c", 'M');

    return 0;
}

