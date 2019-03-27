/* 1016 ²¿·ÖA+B */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 10

int main()
{
    char A[MAX_LEN + 1] = "";
    char B[MAX_LEN + 1] = "";

    int DA, DB;

    scanf("%s%d%s%d", A, &DA, B, &DB);

    int len_a = strlen(A);
    int len_b = strlen(B);

    int PA = 0;
    int PB = 0;

    for (int i = 0; i < len_a; i++)
    {
        if (A[i] == '0' + DA)
        {
            PA = PA * 10 + DA;
        }
    }

    for (int i = 0; i < len_b; i++)
    {
        if (B[i] == '0' + DB)
        {
            PB = PB * 10 + DB;
        }
    }

    printf("%d", PA + PB);

    return 0;
}
