#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int cache[1001], d[1001], degree[1001];
vector<int> adj[1001];

void solve(){
    fill_n(cache, 1001, -1);
    fill_n(d, 1001, 0);
    fill_n(degree, 1001, 0);
    fill_n(adj, 1001, vector<int>(0));

    int n, k, w;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> d[i];
    }
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        degree[y]++;
        adj[x].push_back(y);
    }
    cin >> w;

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i);
            cache[i] = d[i];
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int nxt: adj[now]){
            cache[nxt] = max(cache[nxt], cache[now]+d[nxt]);
            degree[nxt]--;
            if(degree[nxt] == 0) q.push(nxt);
        }
    }
    cout << cache[w] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}