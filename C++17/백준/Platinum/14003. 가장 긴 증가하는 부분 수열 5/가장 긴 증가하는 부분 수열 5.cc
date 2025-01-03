#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), p(n, -1);
    for(int i=0; i<n; i++) cin >> a[i];

    auto cmp = [&](int x, int y){
        return a[x] < a[y];
    };
    multiset<int, decltype(cmp)> s(cmp);
    for(int i=0; i<n; i++){
        s.insert(i);
        auto it = s.lower_bound(i);
        if(it != s.begin()) p[i] = *prev(it);
        if(next(it) != s.end()) s.erase(next(it));
    }

    cout << s.size() << endl;
    vector<int> ans;
    for(int i=*s.rbegin(); i!= -1; i=p[i]) ans.push_back(a[i]);
    reverse(ans.begin(), ans.end());
    for(auto i : ans) cout << i << ' ';
    return 0;
}