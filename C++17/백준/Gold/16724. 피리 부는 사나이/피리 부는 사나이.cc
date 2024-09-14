#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n, m, cnt;
//U는 0, D는 1, L은 2, R은 3
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<int> adj[1000][1000];
bool visited[1000][1000];

void dfs(int y, int x){
    for(auto i: adj[y][x]){
        int nx = x + dx[i], ny = y + dy[i];
        if(!visited[ny][nx]){
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char dir; cin >> dir;
            switch (dir)
            {
            case 'U':
                adj[i][j].push_back(0);
                adj[i-1][j].push_back(1);
                break;
            case 'D':
                adj[i][j].push_back(1);
                adj[i+1][j].push_back(0);
                break;
            case 'L':
                adj[i][j].push_back(2);
                adj[i][j-1].push_back(3);
                break;
            case 'R':
                adj[i][j].push_back(3);
                adj[i][j+1].push_back(2);
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}