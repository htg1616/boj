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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    if(n != m+1){
        cout << "No" << endl;
        return 0;
    }

    int pos = 0;
    int ans = -1;
    for(int i=1; i<=n; i++){
        if(a[pos] == i) pos++;
        else ans = i;
    }
    if(pos != n-1)
        cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        cout << ans << endl;
    }
    return 0;
}