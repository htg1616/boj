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
    //h: 0, p: 1, s: 1
    vector<vector<int>> psum(1+n, vector<int>(3));
    for(int i=1; i<=n; i++){
        char act;
        cin >> act;
        for(int j=0; j<3; j++){
            psum[i][j] += psum[i-1][j];
        }
        if(act == 'H') psum[i][0]++;
        else if(act == 'P') psum[i][1]++;
        else if(act == 'S') psum[i][2]++;
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int act1=0; act1<3; act1++){
            int win1 = (act1+1)%3;
            for(int act2=0; act2<3; act2++){
                int win2 = (act2+1)%3;
                ans = max(ans, psum[i][win1] - psum[0][win1] + 
                psum[n][win2] - psum[i][win2]);
            }
        }
    }

    cout << ans;
    return 0;
}