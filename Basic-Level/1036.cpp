/* 1036 与奥巴马一起编程 */
//!!!注意边界情况：3和20
#include <stdio.h>

#define SIZE 2

int main()
{
    int N, i, j;
    char C[SIZE];

    //1.输入
    scanf("%d%s", &N, C);

    //2.打印
    for (i = 0; i < N; i++)
    {
        printf("%s", C);
    }
    printf("\n");
    for (i = 0; i < (N + 1) / 2 - 2; i++)
    {
        printf("%s", C);
        for (j = 0; j < N - 2; j++)
        {
            printf(" ");
        }
        printf("%s\n", C);
    }
    for (i = 0; i < N; i++)
    {
        printf("%s", C);
    }

    return 0;
}
