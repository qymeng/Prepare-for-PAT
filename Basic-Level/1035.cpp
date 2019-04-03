/* 1035 插入与归并 */
//!!!用sort代替实际算法
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 100

bool isSame(const int *buffer, const int *process, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (buffer[i] != process[i])
        {
            return false;
        }
    }
    return true;
}

void printArray(const int *buffer, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("%d\n", buffer[N - 1]);
}

bool isInsertionSort(const int *primitive, const int *process, int N)
{
    int buffer[MAX_N];
    for (int i = 0; i < N; i++)
    {
        buffer[i] = primitive[i];
    }

    for (int len = 2; len <= N; len++)
    {
        sort(buffer, buffer + len);
        if (isSame(buffer, process, N))
        {
            printf("Insertion Sort\n");
            sort(buffer, buffer + len + 1);
            printArray(buffer, N);
            return true;
        }
    }
    return false;
}

void isMergeSort(const int *primitive, const int *process, int N)
{
    int buffer[MAX_N], i, len;
    bool flag = false;
    for (i = 0; i < N; i++)
    {
        buffer[i] = primitive[i];
    }

    for (len = 2; len <= N; len *= 2)
    {
        for (i = 0; i < N; i += len)
        {
            sort(buffer + i, buffer + (i + len < N ? i + len : N));
        }
        if (flag)
        {
            printf("Merge Sort\n");
            printArray(buffer, N);
            return;
        }
        if (isSame(buffer, process, N))
        {
            flag = true;
        }
    }
}

int main()
{
    int N, i;
    int primitive[MAX_N];
    int process[MAX_N];

    //1.输入
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", primitive + i);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", process + i);
    }

    //2.判断
    if (!isInsertionSort(primitive, process, N))
    {
        isMergeSort(primitive, process, N);
    }

    return 0;
}
