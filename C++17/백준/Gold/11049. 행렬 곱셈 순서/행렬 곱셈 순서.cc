#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;
int n;
int arr_r[500], arr_c[500];
ll cache[501][501];

ll dp(int l, int r){
    ll &ret = cache[l][r];
    if(ret != -1){
        return ret;
    }
    if(r-l == 1){
        return ret = 0;
    }
    ret = 1LL<<31;
    for(int p = l+1; p<r; p++){
        ll check = dp(l, p) + dp(p, r) + arr_r[l] * arr_r[p] * arr_c[r-1]; //todo
        if(check < ret) ret = check;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr_r[i] >> arr_c[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0,n);

    return 0;
}