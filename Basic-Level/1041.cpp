/* 1041 øº ‘◊˘Œª∫≈ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define SIZE 17

struct Student
{
    char num[SIZE];
    int exam;
};

int main()
{
    int N, M, i;
    char num[SIZE];
    int test, exam;
    struct Student buffer[MAX_N + 1];

    //1. ‰»Î
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s%d%d", num, &test, &exam);
        strcpy(buffer[test].num, num);
        buffer[test].exam = exam;
    }

    //2. ‰≥ˆ
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &test);
        printf("%s %d%s", buffer[test].num, buffer[test].exam, i == M - 1 ? "" : "\n");
    }

    return 0;
}
