#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

vector<int> opt;
int cache[100'000][5][5], adj[5][5], n;

int dp(int index, int l, int r){
    if(index == n) return 0;
    int &ret = cache[index][l][r];
    if(ret != -1) return ret;

    int nxt = opt[index];
    ret = min(dp(index+1, nxt, r) + adj[l][nxt], dp(index+1, l, nxt) + adj[r][nxt]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        int num;
        cin >> num;
        if(num == 0) break;
        opt.push_back(num);
        n++;
    }
    for(int i=1; i<=4; i++){
        adj[i][i] = 1;
        adj[0][i] = 2;
        for(int j=1; j<=4; j++){
            if(abs(i-j) == 2) adj[i][j] = 4;
            else if(i!=j) adj[i][j] = 3;
        }
    }
    fill_n(cache[0][0], 100'000*5*5, -1);

    cout << dp(0, 0, 0);
    return 0;
}