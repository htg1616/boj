#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

bool is_in(int x, int y, int cx, int cy, int r){
    return (x-cx)*(x-cx) + (y-cy)*(y-cy) <= r*r;
}

void solve(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n;

    int ans = 0;
    vector<tuple<int, int, int>> p(n);
    for(int i=0; i<n; i++){
        int x, y, r;
        cin >> x >> y >> r;
        if (is_in(x1, y1, x, y, r) != is_in(x2, y2, x, y, r)) ans++;
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}