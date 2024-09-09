#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int SIZE = (1<<21);
int n, tree[2*SIZE];

void update(int x, int val){
    x += SIZE - 1;
    tree[x] += val;
    for(x/=2; x>=1; x/=2){
        tree[x] = tree[x*2] + tree[x*2+1];
    }
}

int query(int x){
    int node = 1;
    while(node < SIZE){
        if(x > tree[2*node]){
            x -= tree[2*node];
            node = 2*node+1;
        }
        else
            node = 2*node;
    }
    int ret = node - (SIZE - 1);
    update(ret, -1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int t, x;
        cin >> t >> x;
        if(t == 1) update(x, 1);
        else cout << query(x) << endl;
    }
    return 0;
}