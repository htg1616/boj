#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, b;
    cin >> n >> k >> b;
    vector<int> arr(n);
    for(int i=0; i<b; i++){
        int num;
        cin >> num;
        arr[num-1] = 1;
    }

    int res = 0;
    for(int i=0; i<k; i++) res += arr[i];

    int ans = res;
    for(int i=k; i<n; i++){
        res += arr[i];
        res -= arr[i-k];
        ans = min(res, ans);
    }

    cout << ans;
    return 0;
}