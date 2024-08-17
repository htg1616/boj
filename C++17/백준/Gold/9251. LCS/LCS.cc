#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;

string s1, s2;
int n1, n2;
int cache[1001][1001];

int dp(int i, int j){
    if(i == 0 || j == 0)
        return 0;

    int& ret = cache[i][j];
    if(ret != -1)
        return ret;
    if(s1[i] == s2[j])
        return ret = dp(i-1, j-1) + 1;
    else
        return ret = max(dp(i-1, j), dp(i, j-1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s1 >> s2;
    n1 = s1.size();
    s1 = ' ' + s1;
    n2 = s2.size();
    s2 = ' ' + s2;
    fill_n(cache[0], 1001*1001, -1);

    cout << dp(n1, n2);

    return 0;
}