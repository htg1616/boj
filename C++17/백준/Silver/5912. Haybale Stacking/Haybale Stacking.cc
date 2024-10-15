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
    vector<int> lsum(1+n), rsum(1+n);
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        lsum[a]++;
        rsum[b]++;
    }
    for(int i=1; i<=n; i++){
        lsum[i] += lsum[i-1];
        rsum[i] += rsum[i-1];
    }

    vector<int> hay;
    for(int i=1; i<=n; i++){
        hay.push_back(lsum[i] - rsum[i-1]);
    }
    sort(hay.begin(), hay.end());
    cout << hay[n/2];
    return 0;
}