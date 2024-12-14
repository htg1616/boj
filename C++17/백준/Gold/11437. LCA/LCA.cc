#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> parent(n+1), height(n+1);
    vector<bool> visited(n+1);
    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    function<void(int)> dfs;
    dfs = [&](int v){
        visited[v] = true;
        for(int nxt: graph[v]){
            if(!visited[nxt]){
                parent[nxt] = v;
                height[nxt] = height[v]+1;
                dfs(nxt);
            }
        }
    };

    dfs(1);

    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        while(height[a] > height[b]) a = parent[a];
        while(height[b] > height[a]) b = parent[b];
        while(a != b){
            a = parent[a];
            b = parent[b];
        }

        cout << a << endl;
    }
    return 0;
}