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
    vector<int> v(n), out(n);
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++){
        int cnt = 0, p=0;
        while(cnt < v[i] || out[p] != 0){
            if(out[p] == 0) cnt++;
            p++;
        }
        out[p] = i+1;
    }

    for(int i=0; i<n; i++) cout << out[i] << ' ';
    return 0;
}