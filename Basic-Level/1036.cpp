/* 1036 ��°���һ���� */
//!!!ע��߽������3��20
#include <stdio.h>

#define SIZE 2

int main()
{
    int N, i, j;
    char C[SIZE];

    //1.����
    scanf("%d%s", &N, C);

    //2.��ӡ
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
