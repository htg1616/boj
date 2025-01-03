#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


__int128_t dp[101][101];

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

__int128_t f(int n, int m){
    if(m==0 || m==n) return 1;
    __int128_t &ret = dp[n][m];
    if(ret != -1) return ret;

    return ret = f(n-1, m-1) + f(n-1, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill_n(dp[0], 101*101, -1);

    int n, m;
    cin >> n >> m;
    print(f(n, m)); 

    return 0;
}