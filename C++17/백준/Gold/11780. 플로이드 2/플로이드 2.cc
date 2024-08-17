#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;

const int INF = 123456789;
int n, m;
int d[101][101];
int nxt[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        fill(d[i], d[i]+1+n, INF);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b;
    }
    for(int i = 1; i<=n; i++) d[i][i] = 0;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j] == INF)
                cout << "0 ";
            else
                cout << d[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j] == 0 || d[i][j] == INF){
                cout << "0" << endl;
                continue;
            }
            vector<int> path;
            int now = i;
            while(now != j){
                path.push_back(now);
                now = nxt[now][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for(auto x : path) cout << x << ' ';
            cout << endl;
        }
    }
    return 0;
}