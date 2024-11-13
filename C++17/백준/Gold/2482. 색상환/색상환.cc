#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int dp[1001][1001];

int comb_mod(int a, int b, int mod){
    if(b<0) return 0;
    
    int &ret = dp[a][b];
    if(ret != -1) return ret;

    if(a==b or b==0) return 1;
    ret = comb_mod(a-1, b-1, mod) + comb_mod(a-1, b, mod);
    ret %= mod;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(dp[0], 1001*1001, -1);

    int n, k;
    cin >> n >> k;

    if(2*k > n){
        cout << 0;
        return 0;
    }

    int mod = 1'000'000'003;
    cout << (comb_mod(n-k+1, k, mod) - comb_mod(n-k-1, k-2, mod) + mod) % mod;

    return 0;
}