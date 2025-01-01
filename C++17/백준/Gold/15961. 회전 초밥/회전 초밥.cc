#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, d, k, c, ans, p=1;
    cin >> n >> d >> k >> c;
    vector<int> a(n), cnt(d+1);
    cnt[c]++;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=n-1; i>=n-k; i--){
        if(cnt[a[i]] == 0) p++;
        cnt[a[i]]++;
    }

    ans = p;

    for(int i=0; i<n; i++){
        if(cnt[a[i]] == 0) p++;
        cnt[a[i]]++;

        cnt[a[(i+n-k)%n]]--;
        if(cnt[a[(i+n-k)%n]] == 0) p--;
        ans = max(ans, p);
    }

    cout << ans;

    return 0;
}