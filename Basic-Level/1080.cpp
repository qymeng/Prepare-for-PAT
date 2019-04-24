/* 1080 MOOC期终成绩 */
//!!!直接剔除编程成绩不合格的来减少样本数，使用map来提高查找效率
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_LEN 21

struct Student
{
    char no[MAX_LEN];
    int p;
    int m;
    int f;
    int total;
};

bool comp(struct Student a, struct Student b)
{
    if (a.total > b.total)
    {
        return true;
    }
    if (a.total < b.total)
    {
        return false;
    }
    return strcmp(a.no, b.no) < 0;
}

int main()
{
    //1.输入
    int P, M, N;
    cin >> P >> M >> N;

    //2.输入
    vector<struct Student> buffer;
    map<string, int> index;
    struct Student temp;
    int i, j;
    int count = 0;

    for (i = 0; i < P; i++)
    {
        cin >> temp.no >> temp.p;
        temp.m = -1;
        temp.f = -1;
        if (temp.p >= 200)
        {
            buffer.push_back(temp);
            index[temp.no] = count;
            count++;
        }
    }

    for (i = 0; i < M; i++)
    {
        cin >> temp.no >> temp.m;
        if (index.count(temp.no) > 0)
        {
            buffer[index[temp.no]].m = temp.m;
        }
    }

    for (i = 0; i < N; i++)
    {
        cin >> temp.no >> temp.f;
        if (index.count(temp.no) > 0)
        {
            buffer[index[temp.no]].f = temp.f;
        }
    }

    //3.算总成绩
    for (i = 0; i < count; i++)
    {
        if (buffer[i].m > buffer[i].f)
        {
            buffer[i].total = (int)((double)buffer[i].m * 0.4 + (double)buffer[i].f * 0.6 + 0.5);
        }
        else
        {
            buffer[i].total = buffer[i].f;
        }
    }

    //4.排序
    sort(buffer.begin(), buffer.begin() + count, comp);

    //5.打印
    for (i = 0; i < count && buffer[i].total >= 60; i++)
    {
        printf("%s %d %d %d %d\n", buffer[i].no, buffer[i].p, buffer[i].m, buffer[i].f, buffer[i].total);
    }

    return 0;
}
