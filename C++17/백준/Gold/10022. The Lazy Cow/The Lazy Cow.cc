#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int new_n = 2*n - 1;
    vector<vector<int>> field(new_n, vector<int>(new_n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> field[i+j][n-i+j-1];
        }
    }

    vector<vector<int>> sump(new_n+1, vector<int>(new_n+1, 0));
    for(int i=1; i<=new_n; i++){
        for(int j=1; j<=new_n; j++){
            sump[i][j] = sump[i-1][j] + sump[i][j-1] - sump[i-1][j-1] + field[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x = i+j;
            int y = n-i+j-1;

            int rx = min(x+k+1, new_n), ry = min(y+k+1, new_n);
            int lx = max(x-k, 0), ly = max(y-k, 0);
            ans = max(ans, sump[rx][ry] - sump[rx][ly]
            -sump[lx][ry] + sump[lx][ly]);
        }
    }

    cout << ans;
    return 0;
}