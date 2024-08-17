#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;
const int INF = 987654321;

int n, w[16][16], cache[1 << 16][16];

// 비트마스킹을 통해 방문처리
int tsp(int visited, int last)
{
    int &ret = cache[visited][last];

    if (ret != -1)
        return ret;

    if (visited == (1 << n) - 1)
    {
        if (w[last][0] == 0)
            return ret = INF;
        else
            return ret = w[last][0];
    }

    ret = INF;
    for (int nxt = 0; nxt < n; nxt++)
    {
        if (w[last][nxt] != 0 && (visited & 1 << nxt) != (1<<nxt))
        {
            ret = min(ret, w[last][nxt] + tsp(visited | 1 << nxt, nxt));
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << tsp(1, 0);
    return 0;
}