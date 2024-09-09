#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int SIZE = (1<<21);
int n, k, tree[2*SIZE];

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

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        tree[i+SIZE-1] = 1;
    }
    for(int i=SIZE-1; i>=1; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    int now = 1;
    cout << "<";
    for(int i=n; i>=1; i--){
        now = (now + k - 2) % i + 1;
        cout << query(now);
        if(i != 1)
            cout << ", ";
    }
    cout << ">";
    return 0;
}