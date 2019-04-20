/* 1070 结绳 */
//!!!前面的绳子相加折半长度不可能大于下一个
#include <stdio.h>
#include <algorithm>
using namespace std;

#define BUFFER_SIZE 10000

int main()
{

    //1.输入
    int N;
    scanf("%d", &N);

    int i;
    double buffer[BUFFER_SIZE];
    for (i = 0; i < N; i++)
    {
        scanf("%lf", buffer + i);
    }

    //2.规约
    sort(buffer, buffer + N);
    double result = buffer[0];
    for (i = 1; i < N; i++)
    {
        result = (result + buffer[i]) / 2;
    }

    //3.输出
    printf("%d", (int)result);

    return 0;
}
