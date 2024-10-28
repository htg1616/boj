#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

constexpr int MAX_N = 600;
constexpr int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
 
int case_dp[MAX_N][MAX_N], field[MAX_N][MAX_N];
int n, m;

int down(int x, int y){
    if(x== m-1 && y == n-1) return 1;

    int &ret = case_dp[x][y];
    if(ret != -1) return ret;

    ret = 00;
    for(int i=0; i<4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(0<=nx && nx<m && 0<=ny && ny<n && field[nx][ny] < field[x][y])
            case_dp[x][y] += down(nx, ny); 
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill_n(case_dp[0], MAX_N*MAX_N, -1);

    cin >> m >> n;
    case_dp[m-1][n-1] = 1;
    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++) cin >> field[x][y];
    }

    cout << down(0, 0) << endl;
    return 0;
}