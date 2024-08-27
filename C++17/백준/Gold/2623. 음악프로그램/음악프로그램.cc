#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n, m, degree[1001];
bool adj[1001][1001], visited[1001];
vector<int> path;
queue<int> zeros;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int l, a, b;
        cin >> l;
        cin >> a;
        for(int j=1; j<l; j++){
            cin >> b;
            if(!adj[a][b]){
                adj[a][b] = 1;
                degree[b]++;
            }
            a = b;
        }
    }

    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            zeros.push(i);
            visited[i] = true;
        }
    }

    while(!zeros.empty()){
        int now = zeros.front();
        path.push_back(now);
        zeros.pop();
        for(int next=1; next<=n; next++){
            if(adj[now][next]){
                if(!visited[next] && --degree[next]==0){
                    visited[next] = true;
                    zeros.push(next);
                }
            }
        }
    }

    if(path.size() < n)
        cout << 0;
    else{
        for(int i: path)
            cout << i << endl;
    }
    return 0;


}