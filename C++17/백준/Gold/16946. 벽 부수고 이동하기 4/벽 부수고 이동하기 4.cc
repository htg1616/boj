#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

constexpr int MAX_N = 1020, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool field[MAX_N][MAX_N];
int ans[MAX_N][MAX_N], set_size[MAX_N][MAX_N];
pair<int, int> parent[MAX_N][MAX_N];

pair<int, int> find(int x, int y){
    auto &p = parent[x][y];
    if(p.X == x && p.Y == y) return {x, y};
    return p = find(p.X, p.Y);
}

void merge(int x1, int y1, int x2, int y2){
    auto p1 = find(x1, y1);
    auto p2 = find(x2, y2);
    if(p2 != p1){
        set_size[p1.X][p1.Y] += set_size[p2.X][p2.Y];
        parent[p2.X][p2.Y] = p1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(set_size[0], MAX_N*MAX_N, 1);

    int n, m;
    cin >> n >> m;
    for(int x=0; x<n; x++){
        string s;
        cin >> s;
        for(int y=0; y<m; y++){
            ans[x][y] = field[x][y] = s[y] - '0';
            parent[x][y] = {x, y};
        }
    }

    
    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            for(int i=0; i<4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(field[x][y] == 0 && field[nx][ny] == 0) merge(x, y, nx, ny);
            }
        }
    }

    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            if(field[x][y] == 0) continue;

            set<pair<int, int>> to_add;
            int cnt = 1;
            for(int i=0; i<4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(field[nx][ny] == 0) to_add.insert(find(nx, ny));
            }
            for(auto p: to_add) cnt += set_size[p.X][p.Y];
            ans[x][y] = cnt;
        }
    }

    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            cout << ans[x][y]%10;
        }
        cout << endl;
    }
    return 0;
}