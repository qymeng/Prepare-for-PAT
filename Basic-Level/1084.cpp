/* 1084 外观数列 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //1.输入
    int d, N;
    scanf("%d %d", &d, &N);

    //2.循环求
    vector<int> buffer[2];
    int i, j;
    int a, b;
    int len;
    int pre, current;
    int count;

    for (i = 0; i < N; i++)
    {
        a = i % 2;
        b = 1 - a;

        if (i == 0)
        {
            buffer[0].push_back(d);
            continue;
        }

        buffer[a].clear();
        len = buffer[b].size();

        for (j = 0; j < len; j++)
        {
            current = buffer[b][j];
            if (j == 0)
            {
                buffer[a].push_back(current);
                buffer[a].push_back(1);
                count = 1;
                continue;
            }

            pre = buffer[b][j - 1];
            if (current == pre)
            {
                buffer[a][count]++;
            }
            else
            {
                buffer[a].push_back(current);
                buffer[a].push_back(1);
                count += 2;
            }
        }
    }

    //3.打印
    len = buffer[a].size();
    for (i = 0; i < len; i++)
    {
        printf("%d", buffer[a][i]);
    }

    return 0;
}
