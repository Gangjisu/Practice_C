#include <stdio.h>
#include <math.h>

int main()
{
    double A,B,C = 0.0;
    double discriminant;
    double root_1,root_2 = 0.0;

    printf("Ax^2 + Bx + C");

    printf("\nInput coefficients (A, B, C):");
    scanf("%lf %lf %lf",&A,&B,&C);

    discriminant = pow(B,2) - 4*A*C; //판별식

    if(A == 0){
        root_1 = (-1 * C) / B;
        printf("root: %.1lf",root_1);
    }
    else
    {
        if(discriminant == 0){//중근
            root_1 = (-1*B + sqrt(discriminant)) / 2*A; //근의 공식
            printf("root: %.1lf",root_1);
        }
        else if(discriminant > 0){//서로다른 두 실근
            root_1 = (-1*B + sqrt(discriminant)) / 2*A; //근의 공식
            root_2 = (-1*B - sqrt(discriminant)) / 2*A; //근의 공식
            printf("root1: %.1lf",root_1);
            printf("\nroot2: %.1lf",root_2);
        }
        else if(discriminant < 0){//서로 다른 두 허근
            printf("imaginary root");
        }
        else    
            printf("something wrong");
    }


    return 0;
}