#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    if(n>=28) cout << (n+6)/7 + 3;
    else{
        int p=0;
        for(; n>0; n-=(p+1), p++);
        cout << p;
    }

    return 0;
}