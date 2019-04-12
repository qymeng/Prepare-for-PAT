#include <stdio.h>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
    return a >= b;
}

int main()
{
    int buffer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    sort(buffer, buffer + 9);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    sort(buffer, buffer + 9, comp);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    return 0;
}
