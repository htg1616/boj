#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for (int i = 0; i < N; ++i)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    long long curl = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
    if(curl > 0) cout << 1;
    else if(curl == 0) cout << 0;
    else cout << -1;
    return 0;
}