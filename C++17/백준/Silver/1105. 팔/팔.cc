#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l, r;
    int p = 1'000'000'000, cnt=0;
    cin >> l >> r;
    while(p > 0){
        int a = l/p%10, b = r/p%10;
        if(a != b) break;
        if(a == 8) cnt++;
        p/=10;
    }
    cout << cnt;
    return 0;
}