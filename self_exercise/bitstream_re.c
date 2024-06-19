#include <stdio.h>

int main() {
    int number;
    unsigned int original_mask = 1 << (sizeof(int) * 8 - 1); // int 타입의 최상위 비트에 해당하는 마스크
    unsigned int mask = original_mask;
    //printf("%u", mask);

    do{
        printf("Enter an integer: ");
        scanf("%d", &number); // 사용자로부터 정수 입력 받기

        printf("The bit stream of %d is: ", number);
        for (int i = 0; i < sizeof(int) * 8; i++) {
            printf("%d", (number & mask) ? 1 : 0); // 마스크와 AND 연산을 통해 해당 위치의 비트를 확인 후 바로 출력
            mask = mask >> 1; // 마스크를 오른쪽으로 1비트씩 이동
        }
        mask = original_mask;//1비트 이동한 마스크를 원래대로 이동
        printf("\n");
    }while(number != 0);

    return 0;
}
//자리수를 이용해서 반복문 안쓰고 어떻게?