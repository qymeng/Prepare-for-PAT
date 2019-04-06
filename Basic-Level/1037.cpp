/* 1037 在霍格沃兹找零钱 */
#include <stdio.h>

#define SIZE 20

struct Money
{
    int Galleon;
    int Sickle;
    int Kunt;
};

void getDifference(struct Money A, struct Money P, struct Money &R)
{
    R.Kunt = A.Kunt - P.Kunt;
    if (R.Kunt < 0)
    {
        R.Kunt += 29;
        A.Sickle--;
    }

    R.Sickle = A.Sickle - P.Sickle;
    if (R.Sickle < 0)
    {
        R.Sickle += 17;
        A.Galleon--;
    }

    R.Galleon = A.Galleon - P.Galleon;
}

int main()
{
    struct Money P, A, R;
    char bufferP[SIZE];
    char bufferA[SIZE];

    //1.输入
    scanf("%s%s", bufferP, bufferA);
    sscanf(bufferP, "%d.%d.%d", &P.Galleon, &P.Sickle, &P.Kunt);
    sscanf(bufferA, "%d.%d.%d", &A.Galleon, &A.Sickle, &A.Kunt);

    //2.输出
    if (A.Galleon > P.Galleon)
    {
        getDifference(A, P, R);
    }
    else if (A.Galleon < P.Galleon)
    {
        printf("-");
        getDifference(P, A, R);
    }
    else if (A.Sickle > P.Sickle)
    {
        getDifference(A, P, R);
    }
    else if (A.Sickle < P.Sickle)
    {
        printf("-");
        getDifference(P, A, R);
    }
    else if (A.Kunt < P.Kunt)
    {
        printf("-");
        getDifference(P, A, R);
    }
    else
    {
        getDifference(A, P, R);
    }
    printf("%d.%d.%d", R.Galleon, R.Sickle, R.Kunt);

    return 0;
}
