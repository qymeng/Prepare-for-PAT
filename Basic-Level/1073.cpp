/* 1073 ��ѡ�ⳣ���Ʒַ� */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5

struct Question
{
    int mark;
    int numOfAnswer;
    int numOfWrong[MAX_N];
    bool answer[MAX_N];
};

int main()
{
    //1.�������
    int N, M;
    scanf("%d %d", &N, &M);
    struct Question *questions = (struct Question *)malloc(M * sizeof(struct Question));

    //2.�������
    int i, j, k;
    int mark, useless, numOfAnswer;
    char inputBuffer[MAX_N];

    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &mark, &useless, &numOfAnswer);
        //��ʼ��
        questions[i].mark = mark;
        questions[i].numOfAnswer = numOfAnswer;
        for (j = 0; j < MAX_N; j++)
        {
            questions[i].numOfWrong[j] = 0;
            questions[i].answer[j] = false;
        }
        for (j = 0; j < numOfAnswer; j++)
        {
            scanf("%s", inputBuffer);
            questions[i].answer[inputBuffer[0] - 'a'] = true;
        }
    }

    // for (i = 0; i < M; i++)
    // {
    //     printf("�� %d ��:\n", i + 1);
    //     printf("������%d ѡ�", questions[i].mark);
    //     for (j = 0; j < MAX_N; j++)
    //     {
    //         if (questions[i].answer[j])
    //         {
    //             printf("%c ", 'a' + j);
    //         }
    //     }
    //     printf("\n");
    // }

    //3.��ȡѡ��
    int max = 0;
    for (i = 0; i < N; i++)
    {
        //printf("�� %d ��ѧ����\n", i + 1);
        double total = 0;
        for (j = 0; j < M; j++)
        {
            scanf("%s", inputBuffer);
            sscanf(inputBuffer, "(%d", &numOfAnswer);

            bool answer[MAX_N] = {0};
            for (k = 0; k < numOfAnswer; k++)
            {
                scanf("%s", inputBuffer);
                answer[inputBuffer[0] - 'a'] = true;
            }

            // printf("�� %d ��Ŀ:", j + 1);
            // for (k = 0; k < MAX_N; k++)
            // {
            //     if (answer[k])
            //     {
            //         printf("%c ", 'a' + k);
            //     }
            // }
            // printf("\n");

            int count = 0;
            bool flag = true;
            for (k = 0; k < MAX_N; k++)
            {
                if (answer[k] == questions[j].answer[k]) //����ȷ
                {
                    if (answer[k])
                    {
                        count++;
                    }
                }
                else if (answer[k]) //��ѡ
                {
                    flag = false;
                    questions[j].numOfWrong[k]++;
                    if (questions[j].numOfWrong[k] > max)
                    {
                        max = questions[j].numOfWrong[k];
                    }
                }
                else //©ѡ
                {
                    questions[j].numOfWrong[k]++;
                    if (questions[j].numOfWrong[k] > max)
                    {
                        max = questions[j].numOfWrong[k];
                    }
                }
            }

            if (flag)
            {
                if (count == questions[j].numOfAnswer)
                {
                    total += questions[j].mark;
                }
                else
                {
                    total += (double)questions[j].mark / 2;
                }
            }
        }
        printf("%.01lf\n", total);
    }

    //4.��ӡ
    if (max == 0)
    {
        printf("Too simple\n");
    }
    else
    {
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < MAX_N; j++)
            {
                if (questions[i].numOfWrong[j] == max)
                {
                    printf("%d %d-%c\n", max, i + 1, 'a' + j);
                }
            }
        }
    }

    free(questions);
    return 0;
}
