#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

vector<ll> a;
ll tree[4'000'001];

void init(int node, int start, int end){
    if(start == end)
        tree[node] = a[start];
    else{
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll query(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    ll lsum = query(node*2, start, (start+end)/2, left, right);
    ll rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

void update(int node, int start, int end, int index, ll val){
    if(index < start || index > end){
        return;
    }
    if(start==end){
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(node*2, start, (start+end)/2, index, val);
    update(node*2+1, (start+end)/2+1, end, index, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, k, q;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        ll num;
        cin >> num;
        a.push_back(num);
    }
    q = m+k;
    init(1, 0, n-1);
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, n-1, b-1, c);
        }
        else{
            cout << query(1, 0, n-1, b-1, c-1) << endl;
        }
    }
    return 0;
}