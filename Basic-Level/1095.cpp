/* 1095 解码PAT准考证 */
//!!!注意输出统计要求是，参数（考场号，日期）的位数
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define BUFFER_SIZE 14
#define NUM_LEN 4
#define DATE_LEN 7
#define ROOM_NUM 1000

struct Candidate
{
    char no[BUFFER_SIZE];
    int grade;
};

struct ExamRoom
{
    int num;
    int count;
};

bool comp1(const struct Candidate a, const struct Candidate b)
{
    if (a.grade != b.grade)
    {
        return a.grade > b.grade;
    }
    else
    {
        return strcmp(a.no, b.no) < 0;
    }
}

bool comp2(const struct ExamRoom a, const struct ExamRoom b)
{
    if (a.count != b.count)
    {
        return a.count > b.count;
    }
    else
    {
        return a.num < b.num;
    }
}

int main()
{
    //1.输入考生数和统计要求个数
    int N, M;
    scanf("%d %d", &N, &M);

    //2.输入考生信息
    vector<struct Candidate> buffer(N);
    int i, j, k;

    for (i = 0; i < N; i++)
    {
        scanf("%s %d", buffer[i].no, &buffer[i].grade);
    }

    //3.输入统计要求
    bool flag;
    int type;

    for (i = 0; i < M; i++)
    {
        scanf("%d", &type);

        flag = true;
        switch (type)
        {
        case 1:
        {
            char rating;
            getchar();
            scanf("%c", &rating);

            sort(buffer.begin(), buffer.begin() + N, comp1);

            printf("Case %d: 1 %c\n", i + 1, rating);
            for (j = 0; j < N; j++)
            {
                if (buffer[j].no[0] == rating)
                {
                    flag = false;
                    printf("%s %d\n", buffer[j].no, buffer[j].grade);
                }
            }

            break;
        }
        case 2:
        {
            int room;
            scanf("%d", &room);
            printf("Case %d: 2 %03d\n", i + 1, room);

            int count = 0;
            int total = 0;
            char temp[NUM_LEN];

            for (j = 0; j < N; j++)
            {
                strncpy(temp, buffer[j].no + 1, 3);
                temp[3] = '\0';
                if (atoi(temp) == room)
                {
                    flag = false;
                    count++;
                    total += buffer[j].grade;
                }
            }

            if (!flag)
            {
                printf("%d %d\n", count, total);
            }

            break;
        }
        case 3:
        {
            int date;
            scanf("%d", &date);
            printf("Case %d: 3 %06d\n", i + 1, date);

            vector<struct ExamRoom> rooms;
            map<int, int> index;
            char temp[DATE_LEN];

            for (j = 0; j < N; j++)
            {
                strncpy(temp, buffer[j].no + 4, 6);
                temp[7] = '\0';
                if (atoi(temp) == date)
                {
                    flag = false;

                    strncpy(temp, buffer[j].no + 1, 3);
                    temp[3] = '\0';
                    int room = atoi(temp);

                    if (index.count(room) == 0)
                    {
                        struct ExamRoom a = {room, 1};
                        rooms.push_back(a);
                        index[room] = rooms.size() - 1;
                    }
                    else
                    {
                        rooms[index[room]].count++;
                    }
                }
            }

            if (!flag)
            {
                int len = rooms.size();
                sort(rooms.begin(), rooms.begin() + len, comp2);
                for (j = 0; j < len; j++)
                {
                    printf("%d %d\n", rooms[j].num, rooms[j].count);
                }
            }
            break;
        }
        }

        if (flag)
        {
            printf("NA\n");
        }
    }

    return 0;
}
