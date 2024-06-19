#include <stdio.h>
//더하기 뺴기 곱하기 나누기
double Add(double a, double b)
{
    return a + b;
}

double Sub(double a,double b)
{   
    if(a > b)
        return a - b;
    else
        return b - a;
}

double Mul(double a,double b)
{
    return a * b;
}

double Div(double a,double b)
{
    return a / b;
}

double func(double (*funcPtr)(double,double))//함수 인자의 타입만 작성하면 된다. 변수명을 써도 무시된다.
{
    printf("input two numbers:");
    double a,b;
    scanf("%lf %lf", &a, &b);

    return funcPtr(a, b);
}

int main() 
{
    int input = 0;

    printf("add : 1, sub : 2, multi : 3, div : 4 : ");
    scanf("%d",&input);

    double result = 0;
    switch (input)
    {
    case 1:
        result = func(Add);
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    }

    printf("%lf",result);
}