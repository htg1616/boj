#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

constexpr int INF = 10000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto bfs = [&](int s, int t){
        queue<int> q;
        q.push(s);
        q.push(t);
        vector<int> distance(n, INF);
        distance[s] = 0;
        distance[t] = 0;
        while(q.size() != 0){
            int v = q.front();
            q.pop();
            for(int w: graph[v]){
                if(distance[w] == INF){
                    distance[w] = distance[v] + 1;
                    q.push(w);
                }
            }
        }

        return distance;
    };

    int mind = 2*INF;
    pair<int, int> ans = {-1, -1};

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            auto dist = bfs(i, j);
            int sumd = accumulate(dist.begin(), dist.end(), 0);
            sumd *= 2;
            if(sumd < mind){
                mind = sumd;
                ans = {i, j};
            }
        }
    }

    cout << ans.X+1 << ' ' << ans.Y+1 << ' ' << mind;

    return 0;
}