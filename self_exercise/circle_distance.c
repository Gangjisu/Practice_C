#include <stdio.h>
#include <math.h>

int main()
{
    int radius;// 반지름
    double area; // 넓이
    int x1,x2,y1,y2; // 점
    double distance; // 거리
    
    //원의 넓이 구하기
    printf("radius:");
    scanf("%d", &radius);
    area = 3.14 * pow(radius,2);
    printf("area:%.2lf\n", area);

    //점과 점사이의 거리
    printf("x1, x2, y1, y2 :");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

    distance = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
    printf("distance : %.2lf",distance);
    
    return 0;
}