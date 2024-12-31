#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    ll ans = 0;
    auto sum = [&](int y1, int y2, int x1, int x2){
        ll ret = 0;
        for(int y=y1; y<y2; y++){
            for(int x=x1; x<x2; x++){
                ret += arr[y][x];
            }
        }
        return ret;
    };

    
    for(int i=1; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans = max(ans, sum(0, i, 0, m) * sum(i, j, 0, m) * sum(j, n, 0, m));
        }
    }
    
    
    for(int i=1; i<m; i++){
        for(int j=i+1; j<m; j++){
            ans = max(ans, sum(0, n, 0, i) * sum(0, n, i, j) * sum(0, n, j, m));
        }
    }
    
    for(int y=1; y<n; y++){
        for(int x=1; x<m; x++){
            ans = max(ans, sum(0, y, 0, x) * sum(0, y, x, m) * sum(y, n, 0, m));
            ans = max(ans, sum(y, n, 0, x) * sum(y, n, x, m) * sum(0, y, 0, m));
            ans = max(ans, sum(0, y, 0, x) * sum(y, n, 0, x) * sum(0, n, x, m));
            ans = max(ans, sum(0, y, x, m) * sum(y, n, x, m) * sum(0, n, 0, x));
        }
    }

    cout << ans;

    return 0;
}