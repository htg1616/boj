#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

struct DSU{
    int n;
    vector<int> v;

    DSU(int _n){
        n = _n;
        v.resize(n);
        iota(v.begin(), v.end(), 0);
    }

    int find(int i){
        if(i != v[i]) v[i] = find(v[i]);
        return v[i];
    }

    void merge(int i, int j){
        if(find(i) != find(j)) v[find(i)] = find(j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    DSU dsu(n+1);
    for(int i=0; i<n-2; i++){
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
    }

    for(int i=2; i<=n; i++){
        if(dsu.find(i) != dsu.find(1)){
            cout << 1 << ' ' << i << endl;
            return 0;
        }
    }
    return 0;
}