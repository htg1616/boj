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
    vector<vector<int>> a(n, vector<int>(m, 0)), b(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++) a[i][j] = s[j]-'0';
    }
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++) b[i][j] = s[j]-'0';
    }

    int cnt = 0;
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-2; j++){
            if(a[i][j] != b[i][j]){
                cnt++;
                for(int x=0; x<3; x++){
                    for(int y=0; y<3; y++){
                        a[i+x][j+y] = 1-a[i+x][j+y];
                    }
                }
            }
        }
    }

    bool chk = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] != b[i][j]) chk = false;
        }
    }

    if(chk) cout << cnt;
    else cout << -1;

    return 0;
}