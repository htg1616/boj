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
    vector<int> a(n), b(n), c(n), d(n), arr1, arr2;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr1.push_back(a[i]+b[j]);
            arr2.push_back(-c[i]-d[j]);
        }
    }
    sort(begin(arr1), end(arr1));
    sort(begin(arr2), end(arr2));

    ll cnt = 0;
    for(int i: arr1){
        cnt += upper_bound(begin(arr2), end(arr2), i) - lower_bound(begin(arr2), end(arr2), i);
    }
    cout << cnt;
    return 0;
}