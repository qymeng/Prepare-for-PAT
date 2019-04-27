/* 1086 就不告诉你 */
//!!!注意结果的前导0
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define RADIX 10

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int result = A * B;
    if (result == 0)
    {
        printf("0");
        return 0;
    }

    vector<int> buffer;
    do
    {
        buffer.push_back(result % RADIX);
        result /= RADIX;
    } while (result != 0);

    int i;
    int len = buffer.size();
    for (i = 0; buffer[i] == 0; i++)
    {
    }
    for (; i < len; i++)
    {
        printf("%d", buffer[i]);
    }

    return 0;
}
