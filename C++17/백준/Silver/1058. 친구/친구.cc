#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<bool>> p(n, vector<bool>(n, false)), q(n, vector<bool>(n, false));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == 'Y'){
                p[i][j] = true;
                q[i][j] = true;
            }
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && p[i][k] && p[k][j]) q[i][j] = true;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(q[i][j]) cnt++;
        }

        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}