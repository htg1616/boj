#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int s, t, d;
    cin >> s >> t >> d;
    cout << (d/(s*2))*t;
    return 0;
}