#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int SIZE = (1<<20);
vector<int> a, b, c;
int n, tree[2*SIZE];

void update(int v){
    v += SIZE - 1;
    tree[v]++;
    for(v/=2; v>=1; v/=2){
        tree[v] = tree[2*v] + tree[2*v+1];
    }
}

int query(int l, int r){
    l += SIZE - 1;
    r += SIZE - 1;
    int ret = 0;
    for(; l<=r; l/=2, r/=2){
        if(l%2 == 1) ret += tree[l++];
        if(r%2 == 0) ret += tree[r--];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        a.push_back(num);
        b.push_back(num);
    }
    sort(b.begin(), b.end());

    ll cnt = 0;
    for(int i: a){
        c.push_back(lower_bound(b.begin(), b.end(), i) - b.begin()+1);
    }
    for(int i: c){
        cnt += query(i+1, n);
        update(i);
    }
    cout << cnt;
    return 0;
}