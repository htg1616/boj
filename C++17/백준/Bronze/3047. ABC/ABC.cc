#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> v;
    for(int i=0; i<3; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<3; i++){
        char c;
        cin >> c;
        cout << v[c-'A'] << ' ';
    }

    return 0;
}