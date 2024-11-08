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
    vector<vector<int>> cnt(m, vector<int>(26));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            cnt[j][s[j]-'A']++;
        }
    }

    string ans = "";
    int d = 0;
    for(int i=0; i<m; i++){
        auto maxp = max_element(begin(cnt[i]), end(cnt[i]));
        d += (n-*maxp);
        ans.push_back('A'+(maxp-begin(cnt[i])));
    }
    cout << ans << endl;
    cout << d << endl;
    return 0;
}