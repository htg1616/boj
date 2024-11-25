#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] *= 2;
        ans = lcm(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}