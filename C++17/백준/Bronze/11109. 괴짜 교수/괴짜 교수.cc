#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

void solve(){
    int d, n, s, p;
    cin >> d >> n >> s >> p;
    int a = d + n*p;
    int b = n*s;
    if(a < b) cout << "parallelize" << endl;
    else if(a > b) cout << "do not parallelize" << endl;
    else cout << "does not matter" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}