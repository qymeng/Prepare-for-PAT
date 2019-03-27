/* 1018 锤子剪刀布 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 2
#define WIN 1
#define LOSE -1
#define DRAW 0

struct Info
{
    int win;
    int lose;
    int draw;
    int B;
    int C;
    int J;
};

//判断函数：p1赢p2，1;p1输p2，-1;平，0
int judge(char action1, char action2)
{
    if (action1 == 'C')
    {
        if (action2 == 'C')
        {
            return DRAW;
        }
        else if (action2 == 'J')
        {
            return WIN;
        }
        else
        {
            return LOSE;
        }
    }
    if (action1 == 'J')
    {
        if (action2 == 'C')
        {
            return LOSE;
        }
        else if (action2 == 'J')
        {
            return DRAW;
        }
        else
        {
            return WIN;
        }
    }
    if (action1 == 'B')
    {
        if (action2 == 'C')
        {
            return WIN;
        }
        else if (action2 == 'J')
        {
            return LOSE;
        }
        else
        {
            return DRAW;
        }
    }
}

//计数
void count(struct Info &p, char action)
{
    if (action == 'C')
    {
        p.C++;
    }
    else if (action == 'J')
    {
        p.J++;
    }
    else
    {
        p.B++;
    }
}

//解
char best(struct Info &p)
{
    if (p.B >= p.C && p.B >= p.J)
    {
        return 'B';
    }
    if (p.C > p.B && p.C >= p.J)
    {
        return 'C';
    }
    if (p.J > p.B && p.J > p.C)
    {
        return 'J';
    }
}

int main()
{
    int N, i;

    //1.输入次数
    scanf("%d", &N);

    // //2.循环输入对局详情
    char action1[MAX_LEN], action2[MAX_LEN];
    struct Info p1, p2;
    memset(&p1, 0, sizeof(struct Info));
    memset(&p2, 0, sizeof(struct Info));

    for (i = 0; i < N; i++)
    {
        scanf("%s%s", action1, action2);

        switch (judge(action1[0], action2[0]))
        {
        case WIN:
        {
            p1.win++;
            p2.lose++;
            count(p1, action1[0]);
            break;
        }
        case LOSE:
        {
            p1.lose++;
            p2.win++;
            count(p2, action2[0]);
            break;
        }
        case DRAW:
        {
            p1.draw++;
            p2.draw++;
            break;
        }
        }
    }

    printf("%d %d %d\n", p1.win, p1.draw, p1.lose);
    printf("%d %d %d\n", p2.win, p2.draw, p2.lose);
    printf("%c %c", best(p1), best(p2));

    return 0;
}
