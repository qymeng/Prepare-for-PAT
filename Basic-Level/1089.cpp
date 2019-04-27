/* 1089 狼人杀-简单版 */
//!!!抽象出模型来很重要
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> statements(N + 1);
    int i, j, k;
    for (i = 1; i <= N; i++)
    {
        cin >> statements[i];
    }

    for (i = 1; i <= N; i++)
    {
        for (j = i + 1; j <= N; j++)
        {
            vector<int> lie;
            vector<int> status(N + 1, 1);
            status[i] = status[j] = -1;

            for (k = 1; k <= N; k++)
            {
                if (statements[k] * status[abs(statements[k])] < 0)
                {
                    lie.push_back(k);
                }
            }

            if (lie.size() == 2 && status[lie[0]] + status[lie[1]] == 0)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    cout << "No Solution" << endl;

    return 0;
}
