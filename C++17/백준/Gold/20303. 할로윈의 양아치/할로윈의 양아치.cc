#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    k--;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int>> bundle(1);
    vector<bool> visited(n, false);
    function<pair<int, int>(int)> dfs;
    dfs = [&](int now){
        int ret = c[now];
        int cnt = 1;
        visited[now] = true;
        for(int nxt: adj[now]){
            if(!visited[nxt]){
                auto p = dfs(nxt);
                ret += p.X;
                cnt += p.Y;
            }
        }
        return make_pair(ret, cnt);
    };
    for(int i=0; i<n; i++){
        if(!visited[i]) bundle.push_back(dfs(i));
    }

    int s = bundle.size() - 1;
    vector<vector<int>> dp(s+1, vector<int>(k+1, 0));
    for(int i=1; i<=s; i++){
        int candy = bundle[i].X;
        int cry = bundle[i].Y;
        for(int j=0; j<=k; j++){
            if(j >= cry) dp[i][j] = max(dp[i-1][j-cry] + candy, dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[s][k];
    return 0;
}