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
    vector<int> psum(1+n);
    for(int i=0; i<n; i++){
        cin >> psum[i+1];
        psum[i+1] = (psum[i] + psum[i+1]) % 7;
    }
    int ans = 0;
    for(int i=0; i<7; i++){
        int minp = 100000;
        int maxp = -1;
        for(int j=0; j<=n; j++){
            if(psum[j] == i){
                minp = min(minp, j);
                maxp = max(maxp, j);
            }
        }
        ans = max(ans, maxp-minp);
    }

    cout << ans;

    return 0;
}