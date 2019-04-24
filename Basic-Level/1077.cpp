/* 1077 互评成绩计算 */
//!!!四舍五入，加1后再除以2
#include <stdio.h>
#include <algorithm>
using namespace std;
#define BUFFER_SIZE 100

int main()
{
    //1.输入参数
    int N, M;
    scanf("%d %d", &N, &M);

    //2.输入
    int teacher;
    int student[BUFFER_SIZE];
    int i, j;
    int temp;
    int count;
    int total;
    double result;

    for (i = 0; i < N; i++)
    {
        scanf("%d", &teacher);

        count = 0;
        total = 0;
        for (j = 0; j < N - 1; j++)
        {
            scanf("%d", &temp);
            if (temp >= 0 && temp <= M)
            {
                student[count++] = temp;
            }
        }

        sort(student, student + count);

        for (j = 1; j < count - 1; j++)
        {
            total += student[j];
        }
        count -= 2;

        result = (double)total / (double)count;
        result += teacher;
        result += 1;
        result /= 2;

        printf("%d\n", (int)result);
    }

    return 0;
}
