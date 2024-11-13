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
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n;  j++){
            cin >> graph[i][j];
        }
    }

    vector<int> visited(1<<n);
    fill(visited.begin(), visited.end(), -1);

    function<int(int, int)> dfs;
    dfs = [&](int visit, int depth){
        if(depth == n) return 0;

        int &ret = visited[visit];
        if(ret != -1) return ret;
        ret = 1e9;
        for(int i=0; i<n; i++){
            if(visit&(1<<i)) continue;
            ret = min(ret, dfs(visit|(1<<i), depth+1) + graph[depth][i]);
        }
        return ret;
    };

    cout << dfs(0, 0);
    return 0;
}