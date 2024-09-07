#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int SIZE = 1<<20, INF = 1'000'000'000;
int min_tree[2*SIZE], max_tree[2*SIZE];

int min_query(int l, int r){
    l += SIZE - 1;
    r += SIZE - 1;
    int ret = INF;
    for(; l<=r; l/=2, r/=2){
        if(l%2 == 1) ret = min(ret, min_tree[l++]);
        if(r%2 == 0) ret = min(ret, min_tree[r--]);
    }
    return ret;
}

int max_query(int l, int r){
    l += SIZE - 1;
    r += SIZE - 1;
    int ret = 0;
    for(; l<=r; l/=2, r/=2){
        if(l%2 == 1) ret = max(ret, max_tree[l++]);
        if(r%2 == 0) ret = max(ret, max_tree[r--]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    fill_n(min_tree, 2*SIZE, INF);
    fill_n(max_tree, 2*SIZE, 0);
    
    for(int i=1; i<=n; i++){
        int num;
        cin >> num;
        min_tree[i + SIZE - 1] = num;
        max_tree[i + SIZE - 1] = num;
    }
    for(int i=SIZE-1; i>=1; i--){
        min_tree[i] = min(min_tree[2*i], min_tree[2*i+1]);
        max_tree[i] = max(max_tree[2*i], max_tree[2*i+1]);
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        cout << min_query(a, b) << ' ' << max_query(a, b) << endl;
    }
    return 0;
}