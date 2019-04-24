/* 1076 WifiÃÜÂë */
#include <stdio.h>

#define MAX_N 4

int main()
{
    int N;
    scanf("%d", &N);

    int i, j;
    char buffer[MAX_N];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < MAX_N; j++)
        {
            scanf("%s", buffer);
            if (buffer[2] == 'T')
            {
                printf("%d", buffer[0] - 'A' + 1);
            }
        }
    }

    return 0;
}
