#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;

int k;
int arr[500];
int sumarr[501];
ll cache[501][501];

ll dp(int l, int r){
    ll &ret = cache[l][r];
    if (cache[l][r] != -1){
        return cache[l][r];
    }
    if (r-l == 1){
        return 0;
    }
    ret = 123456789;
    for (int p = l+1; p < r; ++p) {
        ll check = dp(l, p) + dp(p, r) + sumarr[r] - sumarr[l];
        if (check < ret){
            ret = check;
        }
    }
    return ret;
}

void solve(){
    memset(cache, -1, sizeof(cache));
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
        sumarr[i+1] = sumarr[i] + arr[i];
    }
    cout << dp(0, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t){
        solve();
        t--;
    }
    return 0;
}