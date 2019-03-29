/* 1030 完美数列 */
//!!!也是游标类的题目
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int main()
{
    int N, p, i, j, result;
    int buffer[MAX_N];

    //1.输入
    scanf("%d%d", &N, &p);

    for (i = 0; i < N; i++)
    {
        scanf("%d", buffer + i);
    }

    //2.排序
    sort(buffer, buffer + N);

    //3.循环查找
    for (i = 0, j = 0, result = 0; i < N && j < N; i++) //外循环增大m
    {
        while (j < N && buffer[j] <= (long long)buffer[i] * p) //内循环固定m增大M
        {
            j++;
        }
        result = j - i > result ? j - i : result;
    }

    //4.输出
    printf("%d", result);

    return 0;
}
