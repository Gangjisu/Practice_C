#pragma pack(1); //structure alignment 구조체 맞춤 1byte 단위로 묶는다.
#include <stdio.h>
#include <string.h>

typedef struct StudentCard //학생증? //구조체 tag 
{
    double StuScore; //구조체 member
    char name[20]; 
    /*
    name 변수 1byte 20개 20 byte인데 구조체 맞춤으로 
    가장 많은 바이트 단위로 모든 구조체 맴버의 크기를 통합한다.
    구조체 맴버에 빠르게 접근하기 위해 이러한 형식을 사용한다. 
    #pragma pack(바이트단위 크기)로 맞춤단위를 정해줄 수 있다.
    */
} SCard;

void GetStuScore(SCard arr[], int student_num){

    int input_score;
    char input_name[20]; 

    for(int i = 0; i < student_num; i++)
    {   
        printf("student %d's score: ",i);
        scanf("%d",&input_score);
        arr[i].StuScore = input_score; 

        printf("student %d's name: ",i);
        scanf(" %[^\n]s",input_name); //scan 함수 스킵을 막기 위한 공백 존재 및 newline 입력 전까지 입력받기 중
        strcpy(arr[i].name,input_name);
    }

}

void PrintStuCard(SCard arr[], int student_num)
{

    for(int i = 0; i < student_num; i++)
    {
        printf("\nstudent %d %s: %.2lf ",i,arr[i].name,arr[i].StuScore);
    }
}

double CalcAveScore(SCard arr[], int student_num)
{
    double average_score;

    for(int i = 0; i < student_num; i++)
    {
        average_score += arr[i].StuScore;
    }

    return average_score / (double)student_num;;
}

int StuNumLess(SCard arr[],int student_num,double average_score)
{
    int NOL = 0;

    for(int i = 0; i < student_num; i++)
    {
        if(arr[i].StuScore < average_score)
        {
            NOL++;
        }
    }

    return NOL;
}

/*
모든 학생의 이름과 성적을 출력

최고 성적과 해당 학생 이름 출력

평균 성적 출력

평균 성적 미만 학생 수 출력
*/

int main()
{
    SCard s1;
    printf("%lu \n", sizeof(s1)); //구조체 맞춤 설명하는 것.

    #define SNum 5

    SCard arr[SNum] = { {0,0.}, };

    GetStuScore(arr, SNum);

    PrintStuCard(arr, SNum);

    double aveScore = CalcAveScore(arr, SNum);

    printf("\nAverage score: %.2lf \n", aveScore);

    int num = StuNumLess(arr, SNum, aveScore);

    printf("# of students less than average score: %d \n", num);

    return 0;
}