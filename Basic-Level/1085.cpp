/* 1085 PAT单位排行 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_LEN 7

struct University
{
    char name[MAX_LEN];
    double total;
    int num;
    int rank;
};

bool comp(struct University a, struct University b)
{
    int scoreA = (int)a.total;
    int scoreB = (int)b.total;
    if (scoreA != scoreB)
    {
        return scoreA > scoreB;
    }
    else if (a.num != b.num)
    {
        return a.num < b.num;
    }
    else
    {
        return strcmp(a.name, b.name) <= 0;
    }
}

int main()
{
    //1.输入N
    int N;
    scanf("%d", &N);

    //2.输入考生成绩信息
    char no[MAX_LEN];
    double score;
    char university[MAX_LEN];

    int i, j;
    int len;

    vector<struct University> buffer;
    map<string, int> index;
    struct University temp;
    string strUniversity;

    for (i = 0; i < N; i++)
    {
        //(1)输入
        scanf("%s %lf %s", no, &score, university);
        //(2)将成绩加权化
        switch (no[0])
        {
        case 'B':
        {
            score /= 1.5;
            break;
        }
        case 'A':
        {
            break;
        }
        case 'T':
        {
            score *= 1.5;
            break;
        }
        }
        //(3)将学校名转为小写
        len = strlen(university);
        for (j = 0; j < len; j++)
        {
            if (university[j] >= 'A' && university[j] <= 'Z')
            {
                university[j] += 32;
            }
        }
        //(4)填入
        strUniversity = string(university);
        if (index.count(strUniversity) > 0)
        {
            int tempIndex = index[strUniversity];
            buffer[tempIndex].total += score;
            buffer[tempIndex].num++;
        }
        else
        {
            strcpy(temp.name, university);
            temp.total = score;
            temp.num = 1;
            buffer.push_back(temp);
            index[strUniversity] = buffer.size() - 1;
        }
    }
    //3.排序输出
    len = buffer.size();
    sort(buffer.begin(), buffer.begin() + len, comp);
    printf("%d\n", len);
    for (i = 0; i < len; i++)
    {
        if (i == 0)
        {
            buffer[0].rank = 1;
        }
        else
        {
            if ((int)buffer[i].total == (int)buffer[i - 1].total)
            {
                buffer[i].rank = buffer[i - 1].rank;
            }
            else
            {
                buffer[i].rank = i + 1;
            }
        }
        printf("%d %s %d %d\n", buffer[i].rank, buffer[i].name, (int)buffer[i].total, buffer[i].num);
    }

    return 0;
}
