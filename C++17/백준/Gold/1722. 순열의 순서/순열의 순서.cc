#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

ll fn[21] = {1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=1; i<=20; i++) fn[i] = fn[i-1]*i;

    int n, o;
    cin >> n >> o;
    if(o == 1){
        ll k;
        cin >> k, k--;
        vector<int> a(n), ans;
        iota(a.begin(), a.end(), 1);
        while(n--){
            int t = k/fn[n];
            k %= fn[n];
            ans.push_back(a[t]);
            a.erase(a.begin()+t);
        }
        for(int i: ans) cout << i << ' ';
    }
    else{
        vector<int> a(n), b(n);
        iota(a.begin(), a.end(), 1);
        for(int i=0; i<n; i++) cin >> b[i];
        ll ans = 0;
        for(int i: b){
            n--;
            int t = lower_bound(a.begin(), a.end(), i) - a.begin();
            ans += t*fn[n];
            a.erase(a.begin()+t);
        }
        cout << ans+1;
    }

    return 0;
}