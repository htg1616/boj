#include <bits/stdc++.h>
#define endl '\n'
#define X fisrt
#define Y second
typedef long long ll;
using namespace std;

int n, r, q;
vector<int> adj[100001];
vector<int> child[100001];
int parent[100001];
int cnt[100001];

int dfs(int v){
    for(int x: adj[v]){
        if(x == parent[v]) continue;
        child[v].push_back(x);
        parent[x] = v;
        cnt[v] += dfs(x);
    }
    cnt[v]++;
    return cnt[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> r >> q;
    parent[q] = -1;
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r);
    while(q--){
        int u;
        cin >> u;
        cout << cnt[u] << endl;
    }
    return 0;
}