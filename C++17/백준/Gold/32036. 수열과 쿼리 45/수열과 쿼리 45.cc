#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int q;
    cin >> q;

    priority_queue<ll> small;
    priority_queue<ll, vector<ll>, greater<ll>> large;
    ll s=0, l=0, y=0;
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            ll a, b;
            cin >> a >> b;
            y += b;

            
            if(small.size() > large.size()){
                s += a;
                small.push(a);
                s -= small.top();
                l += small.top();
                large.push(small.top());
                small.pop();
            }
            else{
                l += a;
                large.push(a);
                l -= large.top();
                s += large.top();
                small.push(large.top());
                large.pop();
            }
        }
        else if(t==2){
            ll m = small.top();
            cout << m << ' ' << (l - (ll)large.size()*m) + ((ll)small.size()*m - s) + y << endl;
        }
    }
    return 0;
}