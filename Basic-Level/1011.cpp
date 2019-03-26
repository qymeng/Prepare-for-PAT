/* 1011 A+BºÍC */
#include <stdio.h>

int main()
{
    const char *result[] = {"false", "true"};

    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);

        printf("Case #%d: %s\n", i + 1, result[a + b > c]);
    }

    return 0;
}
