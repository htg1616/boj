#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int SIZE = 1<<20;
int n, m;
ll tree[2*SIZE];

void update(int l, int r, ll k){
    l += SIZE - 1;
    r += SIZE - 1;
    for(; l<=r; l/=2, r/=2){
        if(l%2 == 1) tree[l++] += k;
        if(r%2 == 0) tree[r--] += k;
    }
}

ll query(int x){
    x += SIZE - 1;
    ll ret = tree[x];
    for(x/=2; x>=1; x/=2){
        ret += tree[x];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> tree[i+SIZE-1];
    }
    

    cin >> m;
    while(m--){
        int q;
        cin >> q;
        if(q == 1){
            ll i, j, k;
            cin >> i >> j >> k;
            update(i, j ,k);
        }
        else if(q == 2){
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}