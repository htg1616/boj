#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n, degree[1000];
int adj_cnt[1000][1000];
vector<int> adj[1000];

void dfs(int now){
    while(!adj[now].empty()){
        int nxt = adj[now].back();
        adj[now].pop_back();
        if(adj_cnt[now][nxt] > 0){
            adj_cnt[now][nxt]--;
            adj_cnt[nxt][now]--;
            dfs(nxt);
        }
    }
    cout << now+1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)  for(int j=0; j<n; j++){
        int cnt;
        cin >> cnt;
        for(int k=0; k<cnt; k++){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        adj_cnt[i][j] = cnt;
        adj_cnt[j][i] = cnt;
        if(i<j){
            degree[i] += cnt;
            degree[j] += cnt;
        }
    }
    for(int i=0; i<n; i++){
        if(degree[i] & 1){
            cout << -1;
            return 0;
        }
    }
    dfs(0);
    return 0;
}