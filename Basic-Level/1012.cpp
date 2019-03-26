/* 1012 Êı×Ö·ÖÀà*/
#include <stdio.h>
#include <stdlib.h>

#define N 5

struct Unit
{
    int result;
    int count;
};

int main()
{
    int n, i;
    scanf("%d", &n);

    struct Unit buffer[N];
    for (i = 0; i < N; i++)
    {
        (buffer + i)->result = 0;
        (buffer + i)->count = 0;
    }

    for (i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        switch (temp % 5)
        {
        case 0:
        {
            if (temp % 2 == 0)
            {
                buffer->result += temp;
                buffer->count++;
            }
            break;
        }
        case 1:
        {
            if ((buffer + 1)->count % 2 == 0)
            {
                (buffer + 1)->result += temp;
            }
            else
            {
                (buffer + 1)->result -= temp;
            }
            (buffer + 1)->count++;
            break;
        }
        case 2:
        {
            (buffer + 2)->result++;
            (buffer + 2)->count++;
            break;
        }
        case 3:
        {
            (buffer + 3)->result += temp;
            (buffer + 3)->count++;
            break;
        }
        case 4:
        {
            if ((buffer + 4)->count == 0)
            {
                (buffer + 4)->result = temp;
            }
            else if (temp > (buffer + 4)->result)
            {
                (buffer + 4)->result = temp;
            }
            (buffer + 4)->count++;
            break;
        }
        }
    }

    if ((buffer)->count == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%d ", buffer->result);
    }
    if ((buffer + 1)->count == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%d ", (buffer + 1)->result);
    }
    if ((buffer + 2)->count == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%d ", (buffer + 2)->result);
    }
    if ((buffer + 3)->count == 0)
    {
        printf("N ");
    }
    else
    {
        printf("%.1f ", (float)(buffer + 3)->result / (float)(buffer + 3)->count);
    }
    if ((buffer + 4)->count == 0)
    {
        printf("N");
    }
    else
    {
        printf("%d", (buffer + 4)->result);
    }

    return 0;
}
