#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int SIZE = (1<<20), INF = 1'000'000;

struct Node{
    int min_num, max_num;
};

Node operator+(Node l, Node r){
    return (Node){
        min(l.min_num, r.min_num),
        max(l.max_num, r.max_num)
    };
}

Node tree[2*SIZE];

void update(int x, int v){
    x += SIZE - 1;
    tree[x] = {v, v};
    for(x/=2; x>=1; x/=2){
        tree[x] = tree[2*x] + tree[2*x+1];
    }
}

void change(int l, int r){
    int lval = tree[l+SIZE-1].max_num;
    int rval = tree[r+SIZE-1].max_num;
    update(l, rval);
    update(r, lval);
}

Node query(int l, int r){
    Node ret = {INF, -INF};
    l += SIZE - 1;
    r += SIZE - 1;
    for(; l<=r; l/=2, r/=2){
        if(l%2 == 1) ret = ret + tree[l++];
        if(r%2 == 0) ret = ret + tree[r--];
    }
    return ret;
}

void solve(){
    fill_n(tree, 2*SIZE, Node{INF, -INF});

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        tree[i+SIZE-1] = {i, i};
    }
    for(int i=SIZE-1; i>=1; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    while(k--){
        int q, a, b;
        cin >> q >> a >> b;
        a++; b++;
        if(q == 0) change(a, b);
        else{
            Node res = query(a, b);
            if(res.min_num == a && res.max_num == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}