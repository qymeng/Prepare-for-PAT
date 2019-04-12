/* 1059 CÓïÑÔ¾ºÈü */
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 5
#define MAX_N 10000

struct Student
{
    int award;
    bool checked;
};

bool isPrime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    if (n == 2)
    {
        return true;
    }

    int temp = (int)sqrt((double)n);
    for (int i = 2; i <= temp; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const char *award[] = {
        "Are you kidding?",
        "Mystery Award",
        "Minion",
        "Chocolate"};

    //1.ÊäÈë
    int N;
    scanf("%d", &N);

    struct Student buffer[MAX_N];
    memset(buffer, 0, MAX_N * sizeof(struct Student));
    int i, temp;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        if (i == 0)
        {
            buffer[temp].award = 1;
        }
        else if (isPrime(i + 1))
        {
            buffer[temp].award = 2;
        }
        else
        {
            buffer[temp].award = 3;
        }
    }

    //2.Êä³ö
    int K;
    scanf("%d", &K);

    for (i = 0; i < K; i++)
    {
        scanf("%d", &temp);
        if (buffer[temp].award == 0)
        {
            printf("%04d: %s\n", temp, award[0]);
        }
        else
        {
            if (buffer[temp].checked)
            {
                printf("%04d: %s\n", temp, "Checked");
            }
            else
            {
                printf("%04d: %s\n", temp, award[buffer[temp].award]);
                buffer[temp].checked = true;
            }
        }
    }

    return 0;
}
