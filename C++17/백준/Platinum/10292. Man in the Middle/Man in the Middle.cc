#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int MAX_N = 300001;

vector<int> adj[MAX_N];
int cnt, discover[MAX_N];
bool isman;

int dfs(int now, bool isroot){
    int ret = discover[now] = cnt++;

    int child = 0;
    for(int nxt: adj[now]){
        if(discover[nxt] == -1){
            child++;
            int subtree = dfs(nxt, 0);
            if(!isroot && subtree >= discover[now])
                isman = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discover[nxt]);
    }
    if(isroot && child >= 2)
        isman = true;

    return ret;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<MAX_N; i++){
        adj[i].clear();
    }
    fill_n(discover, MAX_N, -1);
    cnt = 0;
    isman = false;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(discover[i] == -1)
            dfs(i, 1);
    }
    if(isman)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}