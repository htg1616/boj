#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;
const int MAX_N = 1'000'000;

int n;
vector<int> adj[MAX_N+1], child[MAX_N+1];
int visited[MAX_N+1], cache[MAX_N+1][2];

void dfs(int now){
    visited[now] = 1;
    for(int next: adj[now]){
        if(!visited[next]){
            child[now].push_back(next);
            dfs(next);
        }
    }
}

int dp(int node, int isearly){
    if(child[node].empty())
        return isearly;
    int &ret = cache[node][isearly];
    if(ret != -1)
        return ret;

    if(isearly){
        ret = 1;
        for(int next: child[node])
            ret += min(dp(next, 0), dp(next, 1));
        return ret;
    }
    else{
        ret = 0;
        for(int next:child[node]){
            ret += dp(next, 1);
        }
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(cache[0], MAX_N*2, -1);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << min(dp(1, 0), dp(1, 1));
    return 0;
}