#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> p(m);
    for(int i=0; i<m; i++){
        cin >> p[i].X >> p[i].Y;
    }
    sort(p.begin(), p.end());

    auto check = [&](ll d){
        int interval = 0;
        ll pos = p[0].X;
        for(int i=0; i<n-1; i++){
            pos += d;
            if(pos > p[interval].Y){
                while(interval < m and p[interval].Y < pos) interval++;
                if(interval == m) return false;
                pos = max(pos, p[interval].X);
            }
        }
        return true;
    };

    ll start = 1, end = (1LL)<<60;
    while(start<end){
        ll mid = start + (end-start+1)/2;
        if(check(mid)) start = mid;
        else end = mid-1; 
    }
    
    cout << start << endl;
    return 0;
}