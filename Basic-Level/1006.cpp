/*1006 换个格式输出整数*/
#include <stdio.h>

int main()
{
    int input;
    scanf("%d", &input);

    int i;
    int hundred = input / 100;
    for (i = 0; i < hundred; i++)
    {
        printf("B");
    }

    int ten = input % 100 / 10;
    for (i = 0; i < ten; i++)
    {
        printf("S");
    }

    int one = input % 10;
    for (i = 1; i <= one; i++)
    {
        printf("%d", i);
    }

    return 0;
}
