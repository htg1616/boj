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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int left = 0, right = n-1, ans = 200'000'001;
    while(left < right){
        int p = a[left] + a[right];
        if(abs(p) < abs(ans)) ans = p;
        if(p<0) left++;
        else right--;
    }

    cout << ans;
    return 0;
}