/* 1072 开学寄语 */
#include <stdio.h>

#define BUFFER_SIZE 10000
#define MAX_LEN 5

int main()
{
    //1.输入
    int N, M;
    scanf("%d %d", &N, &M);

    bool buffer[BUFFER_SIZE] = {0};
    int i, temp;
    for (i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        buffer[temp] = true;
    }

    //2.检查
    int nStudent = 0;
    int nItem = 0;
    char name[MAX_LEN];
    int j, num, nPerson;

    for (i = 0; i < N; i++)
    {
        scanf("%s %d", name, &num);
        nPerson = 0;
        for (j = 0; j < num; j++)
        {
            scanf("%d", &temp);
            if (buffer[temp])
            {
                nPerson++;
                nItem++;
                if (nPerson == 1)
                {
                    nStudent++;
                    printf("%s:", name);
                }
                printf(" %04d", temp);
            }
        }
        if (nPerson > 0)
        {
            printf("\n");
        }
    }
    printf("%d %d\n", nStudent, nItem);

    return 0;
}
