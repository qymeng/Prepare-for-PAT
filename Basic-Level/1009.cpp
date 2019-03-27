/* 1009 Ëµ·´»° */
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

#define MAX_LEN 80

int main()
{
    stack<string> buffer;
    char input[MAX_LEN];

    while (1)
    {
        scanf("%s", input);
        buffer.push(input);
        if (getchar() == '\n')
        {
            break;
        }
    }

    while (!buffer.empty())
    {
        printf("%s%s", buffer.top().c_str(), buffer.size() == 1 ? "" : " ");
        buffer.pop();
    }

    return 0;
}