#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n;
int weights[10001];
vector<int> adj[10001], child[10001];
int visited[10001];
int cache[10001][2];
vector<int> path;

void dfs(int now){
    visited[now] = 1;
    for(int next: adj[now]){
        if(!visited[next]){
            child[now].push_back(next);
            dfs(next);
        }
    }
}

int dp(int node, int isset){
    if(child[node].size() == 0) return isset ? weights[node] : 0;
    int &ret = cache[node][isset];
    if(ret != -1) return ret;

    if(isset){
        ret = weights[node];
        for(int next: child[node]){
            ret += dp(next, 0);
        }
        return ret;
    }
    else{
        ret = 0;
        for(int next: child[node]){
            ret += max(dp(next, 1), dp(next, 0));
        }
        return ret;
    }
}

void track(int node, int isset){
    if(isset){
        path.push_back(node);
        for(int next: child[node]){
            track(next, 0);
        }
    }
    else{
        for(int next: child[node]){
            if(dp(next, 1) > dp(next, 0)) track(next, 1);
            else track(next, 0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> weights[i];
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(cache[0], 10001*2, -1);
    dfs(1);
    child[0].push_back(1);
    cout << dp(0, 0) << endl;
    track(0, 0);
    sort(path.begin(), path.end());
    for(int x: path)
        cout << x << ' ';
    return 0;
}