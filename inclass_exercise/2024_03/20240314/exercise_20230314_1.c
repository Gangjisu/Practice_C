#include<stdio.h>

int main()
{
    int age = 0;
    double height = 0.0;
    char gender;
    char name[50] = {'\0',}; //뒤에는 배열의 디폴트 값으로 된다.
    
    printf("\ngender: ");
    scanf("%c", &gender); 
    
    //getchar(); //개행문자입력을 받아 뒤에 문자형(열)입력이 스킵되는 것을 방지한다. 모든 문자를 받을 때는 앞에 개행문자르 유념

    printf("name: ");
    scanf(" %[^\n]s", name); //문자열은 자체만으로도 주소형태 포인터형태이기에 &을 입력하면 안된다. //[^\n]  개행문자가 입력될때까지 입력을 받는다. 이것 알아볼것
    printf("\nage: ");
    scanf("%d", &age);
    printf("\nheight: ");
    scanf("%lf", &height);
    
    
    printf("MY information:\n\t이름:%s\n\t나이:%d\n\t키:%.1lf\n\t성별:%c\n\t",name,age,height,gender);
    

    return 0;
}

/*
    char 입력시 enter(개행문자입력)으로 인해 스킵된는 것을 막기 위해서 앞에 한칸을 형식지정자 앞의 한칸을 띄우면된다.
    vs 기준으로 보안 오류가 발생하면 scan_s라는 함수를 사용하거나 #define _CRT_SECURE_NO_WARNINGS 을 위에 넣는다.

*/