#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int INF = 12345678;

int a, b;
int cache[1'000'001][2];
int dp(int now, int used){
    int &ret = cache[now][used];
    if(now == b)
        return 0;
    if(ret != -1)
        return ret;
    
    ret = INF;
    vector<int> nxt_arr;
    nxt_arr.push_back(now*2);
    nxt_arr.push_back(now+1);

    for(int nxt: nxt_arr){
        if(nxt <= b){
            ret = min(ret, dp(nxt, used) + 1);
        }
    }

    if(now*10 <= b && used == 0){
        ret = min(ret, dp(now*10, 1) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    fill_n(cache[0], 1'000'001*2, -1);

    cout << dp(a, 0);
    return 0;
}