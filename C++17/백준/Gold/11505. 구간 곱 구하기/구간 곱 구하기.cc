#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int SIZE = 1<<20, MOD = 1'000'000'007;
int n, m, k;
ll tree[2*SIZE];

void update(int x, int v){
    x += SIZE - 1;
    tree[x] = v;
    for(x/=2; x>=1; x/=2){
        tree[x] = tree[2*x] * tree[2*x+1] % MOD;
    }
}

ll query(int l, int r){
    ll ret = 1;
    l += SIZE - 1;
    r += SIZE - 1;
    for(; l<=r; l/=2, r/=2){
        if(l%2 == 1) ret = ret * tree[l++] % MOD;
        if(r%2 == 0) ret = ret * tree[r--] % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(tree, 2*SIZE, 1);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> tree[i+SIZE-1];
    }
    for(int i=SIZE-1; i>=1; i--){
        tree[i] = tree[2*i] * tree[2*i+1] % MOD;
    }

    while(m>0 || k>0){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
            m--;
        }
        else if(a == 2){
            cout << query(b, c) << endl;
            k--;
        }
    }
    return 0;
}