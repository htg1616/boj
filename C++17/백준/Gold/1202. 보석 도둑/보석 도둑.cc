#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> gems(n); //x: m, y: v
    vector<int> bags(k);
    for(int i=0; i<n; i++) cin >> gems[i].X >> gems[i].Y;
    for(int i=0; i<k; i++) cin >> bags[i];
    sort(begin(gems), end(gems));
    sort(begin(bags), end(bags));

    priority_queue<int> avail;

    ll ans = 0;
    int pos = 0;
    for(int c: bags){
        while(pos < n && gems[pos].X <= c){
            avail.push(gems[pos].Y);
            pos++;
        }
        if(!avail.empty()){
            ans += avail.top();
            avail.pop();
        }
    }

    cout << ans;

    return 0;
}