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
    vector<pair<int, int>> gems(n);
    multiset<int> bags; //x: v, y: m
    for(int i=0; i<n; i++) cin >> gems[i].Y >> gems[i].X;
    for(int i=0; i<k; i++){
        int num;
        cin >> num;
        bags.insert(num);
    }
    sort(rbegin(gems), rend(gems));

    ll ans = 0;
    for(auto p: gems){
        int m = p.Y, v = p.X;
        auto it = bags.lower_bound(m);
        if(it != bags.end()){
            bags.erase(it);
            ans += v;
        }
    }

    cout << ans;

    return 0;
}