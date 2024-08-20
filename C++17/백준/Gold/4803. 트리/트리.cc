#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int cas;
int n, m;
vector<int> adj[501];
int visited[501];

int dfs(int v, int before){
    visited[v] = 1;
    for(int next: adj[v]){
        if(visited[next] and next != before){
            return 0;
        }
        if(!visited[next] and !dfs(next, v))
            return 0;
    }
    return 1;
}

void solve(int n, int m){
    fill_n(visited, 501, 0);
    fill_n(adj, 501, vector<int>(0));
    int ans = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        ans += dfs(i, 0);
    }
    cout << "Case " << cas << ": ";
    if(ans == 0) cout << "No trees." << endl;
    else if(ans == 1) cout << "There is one tree." << endl;
    else cout << "A forest of " << ans << " trees." << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        cas++;
        cin >> n >> m;
        if(n == 0 and m == 0) break;
        solve(n, m);
    }
    return 0;
}