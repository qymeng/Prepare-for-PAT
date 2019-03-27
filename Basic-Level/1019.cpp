/* 1019 数字黑洞 */
#include <stdio.h>
#include <algorithm>
using namespace std;

#define LEN 4
#define END 6174

void separate(int N, int *buffer)
{
    int i;
    for (i = 0; i < LEN; i++)
    {
        buffer[i] = N % 10;
        N /= 10;
    }
}

bool comp(int a, int b)
{
    return a > b;
}

void unite(int &result, const int *buffer)
{
    int i;
    for (i = 0, result = 0; i < LEN; i++)
    {
        result = result * 10 + buffer[i];
    }
}

bool isSame(const int *buffer)
{
    int i;
    for (i = 1; i < LEN; i++)
    {
        if (buffer[i] != buffer[0])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    int up, down;
    int buffer[4];

    //1.输入
    scanf("%d", &N);

    //2.循环过程
    while (1)
    {
        separate(N, buffer);

        if (isSame(buffer))
        {
            printf("%d - %d = 0000", N, N);
            break;
        }

        sort(buffer, buffer + LEN);
        unite(up, buffer);
        sort(buffer, buffer + LEN, comp);
        unite(down, buffer);

        N = down - up;

        printf("%04d - %04d = %04d\n", down, up, N);

        if (N == END)
        {
            break;
        }
    }

    return 0;
}
