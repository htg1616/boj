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
    vector<int> a(n), b(n), ord(n+1), d(n, 1), p(n, -1);
    for(int i=0; i<n; i++){
        cin >> a[i];
        ord[a[i]] = i; 
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        b[i] = ord[b[i]];
    }

    int ans = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(b[j] < b[i] && d[i] < d[j]+1){
                d[i] = d[j]+1;
                p[i] = j;
            }
            ans = max(ans, d[i]);
        }
    }
    
    cout << ans << endl;
    vector<int> out;
    for(int i=n-1; i>=0; i--){
        if(d[i] == ans){
            for(int j=i; j!=-1; j=p[j]) out.push_back(a[b[j]]);
            break;
        }
    }
    sort(out.begin(), out.end());
    for(int i: out) cout << i << ' ';
    return 0;
}