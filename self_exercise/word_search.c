#include <stdio.h>

int main()
{
    char target_arr[1000] = {'0', };
    char search_arr[10] = {'0', };

    printf("Input your strings(less than 1000 chars): ");
    scanf("%[^\n]s", target_arr);

    getchar();

    printf("search your strings(less than 10 chars): ");
    scanf("%[^\n]s", search_arr);

    char *s_arr = search_arr;
    const char *t_arr = target_arr;
    int matched = 0;
    while (*t_arr != '\0')
    {
        if(*t_arr == *s_arr)
        {
            printf("\n%c: %c",*s_arr,*t_arr);
            s_arr++;
        }
        else
        {   
            s_arr = &search_arr[0];
        }
        
        if(*s_arr == '\0')
        {
            matched++;
            t_arr++;
        }
        else
        {
            t_arr++;
        }
    }
    
    printf("\nMatched count:%d", matched);
        
    return 0;
}