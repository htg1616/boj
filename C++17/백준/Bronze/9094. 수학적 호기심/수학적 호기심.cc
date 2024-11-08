#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    for(int a=1; a<n; a++){
        for(int b=a+1; b<n; b++){
            if((a*a+b*b+m) % (a*b) == 0) cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}