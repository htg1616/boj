#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int n, m;
vector<int> adj[501];
int degree[501];
bool adj_arr[501][501];

pair<vector<int>, int> top_sort(){
    queue<int> q;
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0)
            q.push(i);
    }

    int ispos = 0; //0은 가능, 1은 ?, 2는 IMPOSSIBLE 의미
    while(!q.empty()){
        if(q.size() >= 2) ispos =  1;
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for(int next: adj[now]){
            if(--degree[next] == 0)
                q.push(next);
        }
    }
    if(ans.size() < n) ispos = 2;

    return {ans, ispos};
}

void solve(){
    fill_n(adj, 501, vector<int>(0));
    fill_n(degree, 501, 0);
    fill_n(adj_arr[0], 501*501, 0);

    cin >> n;
    vector<int> t;
    for(int i=0; i<n; i++){
        int ti;
        cin >> ti;
        t.push_back(ti);
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            adj_arr[t[i]][t[j]] = 1;
        }
    }

    cin >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj_arr[a][b] = 1 - adj_arr[a][b];
        adj_arr[b][a] = 1 - adj_arr[b][a];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(adj_arr[i][j]){
                adj[i].push_back(j);
                degree[j]++;
            }
        }
    }

    auto res = top_sort();
    vector<int> ans = res.X;
    int ispos = res.Y;

    if(ispos == 0){
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    else if(ispos == 1)
        cout << '?' << endl;
    else
        cout << "IMPOSSIBLE" << endl;
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