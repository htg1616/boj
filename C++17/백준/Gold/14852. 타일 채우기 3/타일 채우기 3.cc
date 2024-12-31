#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

constexpr int MOD = 1'000'000'007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 7;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = (arr[i - 1] * 3 + arr[i - 2] - arr[i - 3] + MOD) % MOD;
    }

    cout << arr[n];

    return 0;
}