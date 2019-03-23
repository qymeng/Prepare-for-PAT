#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 15

struct Student
{
    char name[MAX_LEN];
    char num[MAX_LEN];
    int score;
};

int main()
{
    int n = 0, i;
    scanf("%d", &n);

    struct Student *buffer = (struct Student *)malloc(n * sizeof(struct Student));
    memset(buffer, 0, n * sizeof(struct Student));
    for (i = 0; i < n; i++)
    {
        scanf("%s%s%d", buffer[i].name, buffer[i].num, &buffer[i].score);
    }

    int max = 0;
    int min = 0;
    for (i = 1; i < n; i++)
    {
        if (buffer[i].score > buffer[max].score)
        {
            max = i;
        }
        else if (buffer[i].score < buffer[min].score)
        {
            min = i;
        }
    }

    printf("%s %s\n", buffer[max].name, buffer[max].num);
    printf("%s %s\n", buffer[min].name, buffer[min].num);

    free(buffer);

    return 0;
}