#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

vector<ll> num;
ll a;

void dfs(int last){
    for(int i=0; i<last; i++){
        a = a*10 + i;
        num.push_back(a);
        dfs(i);
        a /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dfs(10);
    sort(num.begin(), num.end());

    int n;
    cin >> n;
    if(n >= (ll)num.size()) cout << -1;
    else cout << num[n];
    
    return 0;
}