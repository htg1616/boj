#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll x, y;
    cin >> x >> y;

    ll n=1, cnt=0;
    for(; n*(n+1)/2 < x+y; n++);
    if(n*(n+1)/2 != x+y){
        cout << -1;
        return 0;
    }
    for(; x>0; x-=n, n--, cnt++);
    cout << cnt;
    return 0;
}