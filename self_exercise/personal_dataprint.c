#include <stdio.h>
#include <string.h>
/*
My information:

(탭)
이름: 홍길동

나이: 20세

키: xxx.x cm
(-> 정수 및 소수 자릿수 지정할 것)

성별: M (또는 F)
*/
int main()
{   
    //변수 선언
    char name;
    int age = 0;
    double height = 0.0;
    char gender;
    int i = 0;

    //입력
    printf("\ngender: ");
    scanf("%c", &gender); //스트링 뒤에 와야지만 된다.
    printf("name: ");
    scanf("%s", &name);
    printf("\nage: ");
    scanf("%d", &age);
    printf("\nheight: ");
    scanf("%lf", &height);
    

    //출력
    printf("My information:\n\n\t이름: %s\n\n\t나이: %d\n\n\t키: %3.1lf cm\n\n\t성별: %c",name,age,height,gender);

    return 0;
}
