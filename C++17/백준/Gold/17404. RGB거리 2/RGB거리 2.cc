#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int INF = 123456789;
int n;
int cost[1001][3];
int cache[1001][3][3];

int dp(int index, int color, int color_last){
    int &ret = cache[index][color][color_last];
    if(ret != -1) return ret;
    if(index == 0 && color == color_last){
        return ret = INF;
    }
    if(index == n-1){
        if(color == color_last) return ret = cost[n-1][color];
        else return ret = INF;
    }

    ret = INF;
    for(int i=0; i<3; i++){
        if(i == color) continue;
        ret = min(dp(index+1, i, color_last), ret);
    }
    ret += cost[index][color];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> cost[i][j];
        }
    }
    fill_n(cache[0][0], 1001*3*3, -1);

    int ans = INF;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans = min(ans, dp(0, i, j));
        }
    }
    cout << ans;
    return 0;
}