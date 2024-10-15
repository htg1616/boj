#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> diff(1+n);
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        diff[a]++;
        diff[b+1]--;
    }
    int res = 0;
    vector<int> hay;
    for(int i=0; i<n; i++){
        res += diff[i];
        hay.push_back(res);
    }
    sort(hay.begin(), hay.end());
    cout << hay[n/2];
    return 0;
}