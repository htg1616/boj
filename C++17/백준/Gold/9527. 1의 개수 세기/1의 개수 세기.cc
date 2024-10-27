#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

ll cnt_binary(ll n){
    n++;
    ll ans = 0;
    for(ll i=1; i<n; i*=2){
        ans += n - i*(n/(2*i)) - min(n%(2*i),i);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a, b;
    cin >> a >> b;
    cout << cnt_binary(b) - cnt_binary(a-1);
    return 0;
}