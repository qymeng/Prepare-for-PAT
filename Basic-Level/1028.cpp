/* 1028 人口普查 */
//!!!坑点：如果所有的生日都不合法，则最后只输出有效生日个数为0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 6
#define DATE_LEN 11
#define EARLIER -1
#define SAME 0
#define LATER 1

struct Person
{
    char name[NAME_LEN];
    int year;
    int month;
    int day;
};

int compDate(int year1, int month1, int day1, int year2, int month2, int day2)
{
    if (year1 > year2)
    {
        return LATER;
    }
    if (year1 < year2)
    {
        return EARLIER;
    }
    if (month1 > month2)
    {
        return LATER;
    }
    if (month1 < month2)
    {
        return EARLIER;
    }
    if (day1 > day2)
    {
        return LATER;
    }
    if (day1 < day2)
    {
        return EARLIER;
    }

    return SAME;
    {
        /* data */
    };
}

bool isValid(int year, int month, int day)
{
    if (compDate(year, month, day, 2014, 9, 6) == LATER)
    {
        return false;
    }
    if (compDate(year, month, day, 1814, 9, 6) == EARLIER)
    {
        return false;
    }

    return true;
}

int main()
{
    int N, valid, i;
    char name[NAME_LEN], date[DATE_LEN];
    struct Person oldest, youngest;
    int year, month, day;

    //1.输入
    scanf("%d", &N);

    for (i = 0, valid = 0; i < N; i++)
    {
        scanf("%s %s", name, date);

        year = atoi(date);
        month = atoi(date + 5);
        day = atoi(date + 8);

        if (isValid(year, month, day))
        {
            valid++;

            if (valid == 1)
            {
                strcpy(oldest.name, name);
                oldest.year = year;
                oldest.month = month;
                oldest.day = day;

                strcpy(youngest.name, name);
                youngest.year = year;
                youngest.month = month;
                youngest.day = day;
            }
            else
            {
                if (compDate(year, month, day, oldest.year, oldest.month, oldest.day) == EARLIER)
                {
                    strcpy(oldest.name, name);
                    oldest.year = year;
                    oldest.month = month;
                    oldest.day = day;
                }
                if (compDate(year, month, day, youngest.year, youngest.month, youngest.day) == LATER)
                {
                    strcpy(youngest.name, name);
                    youngest.year = year;
                    youngest.month = month;
                    youngest.day = day;
                }
            }
        }
    }

    if (valid)
    {
        printf("%d %s %s", valid, oldest.name, youngest.name);
    }
    else
    {
        printf("%d", valid);
    }

    return 0;
}
