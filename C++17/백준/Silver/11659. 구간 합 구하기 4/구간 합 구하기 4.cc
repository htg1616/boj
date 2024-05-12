#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> sumprefix(n+1);
    sumprefix[0] = 0;
    FOR(i, n){
        cin >> a;
        sumprefix[i+1] = sumprefix[i] + a;
    }
    FOR(i, m){
        cin >> a >> b;
        cout << sumprefix[b] - sumprefix[a-1] << endl;
    }
    return 0;
}