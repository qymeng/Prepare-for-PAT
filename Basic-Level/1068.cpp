/* 1068 万绿丛中一点红 */
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    //1.输入参数
    int M, N, TOL;
    scanf("%d%d%d", &M, &N, &TOL);

    //2.读取点
    int i, j;
    int buffer[N + 2][M + 2];
    for (i = 0; i < N + 2; i++)
    {
        for (j = 0; j < M + 2; j++)
        {
            buffer[i][j] = -TOL;
        }
    }
    map<int, int> colorCount;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            scanf("%d", &buffer[i][j]);
            colorCount[buffer[i][j]]++;
        }
    }

    //3.判断
    int temp;
    vector<int> color;
    int x;
    int y;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            temp = buffer[i][j];
            if (colorCount[temp] > 1)
            {
                continue;
            }
            if (abs(buffer[i - 1][j - 1] - temp) <= TOL)
            {
                continue;
            }
            if (abs(buffer[i - 1][j] - temp) <= TOL)
            {
                continue;
            }
            if (abs(buffer[i - 1][j + 1] - temp) <= TOL)
            {
                continue;
            }
            if (abs(buffer[i][j - 1] - temp) <= TOL)
            {
                continue;
            }
            if (abs(buffer[i][j + 1] - temp) <= TOL)
            {
                continue;
            }
            if (abs(buffer[i + 1][j - 1] - temp) <= TOL)
            {
                continue;
            }
            if (abs(buffer[i + 1][j] - temp) <= TOL)
            {
                continue;
            }
            if (abs(buffer[i + 1][j + 1] - temp) <= TOL)
            {
                continue;
            }

            color.push_back(temp);
            x = j;
            y = i;
        }
    }

    //4.输出
    if (color.size() > 1)
    {
        printf("Not Unique\n");
    }
    else if (color.size() == 1)
    {
        printf("(%d, %d): %d\n", x, y, color[0]);
    }
    else
    {
        printf("Not Exist\n");
    }

    return 0;
}
