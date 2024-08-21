#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n;
int people[10001], visited[10001], cache[10001][2];
vector<int> adj[10001], child[10001];

void dfs(int now){
    visited[now] = 1;
    for(int next: adj[now]){
        if(!visited[next]){
            child[now].push_back(next);
            dfs(next);
        }
    }
}

int dp(int now, int isgood){
    if(child[now].empty()) return isgood ? people[now] : 0;
    int &ret = cache[now][isgood];
    if(ret != -1) return ret;

    if(isgood){
        ret = people[now];
        for(int next: child[now])
            ret += dp(next, 0);
        return ret;
    }
    else{
        ret = 0;
        for(int next: child[now])
            ret += max(dp(next, 1), dp(next, 0));
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> people[i];
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(cache[0], 10001*2, -1);
    dfs(1);
    cout << max(dp(1, 0), dp(1, 1));
    return 0;
}