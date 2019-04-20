/* 1065 单身狗 */
#!!!注意输出格式，不足5位要有前导0
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define BUFFER_SIZE 100000

int main()
{
    //1.输入
    int N;
    scanf("%d", &N);

    int i;
    int a, b;
    int buffer[BUFFER_SIZE];
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = -1;
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        buffer[a] = b;
        buffer[b] = a;
    }

    int M;
    scanf("%d", &M);

    bool attend[BUFFER_SIZE] = {0};
    vector<int> single;
    int temp;
    for (i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        attend[temp] = true;
    }
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        if (attend[i])
        {
            int temp = buffer[i];
            if (temp < 0 || !attend[temp])
            {
                single.push_back(i);
            }
        }
    }

    int n = single.size();
    printf("%d\n", n);
    sort(single.begin(), single.begin() + n);
    for (i = 0; i < n; i++)
    {
        printf("%s%05d", i == 0 ? "" : " ", single[i]);
    }

    return 0;
}
