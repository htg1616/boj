#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int g, p;
    cin >> g >> p;
    vector<int> gi(p);
    set<int> s;
    for(int i=1; i<=g; i++) s.insert(i);
    for(int& i: gi) cin >> i;

    int cnt = 0;
    for(int i: gi){
        auto it = s.upper_bound(i);
        if(it == s.begin()) break;
        it--;
        s.erase(it);
        cnt++;
    }

    cout << cnt;

    return 0;
}