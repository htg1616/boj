#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, arr[6], t, p;
    cin >> n;
    FOR(i, 6){
        cin >> arr[i];
    }
    cin >> t >> p;

    ll tshirt = 0;
    FOR(i, 6){
        tshirt += ((arr[i] + t - 1) / t);
    }
    cout << tshirt << endl;

    cout << n/p << " " << n%p;
    return 0;
}