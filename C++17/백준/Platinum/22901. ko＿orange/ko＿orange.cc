#include <bits/stdc++.h>
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int INF = 123456789;
int t[301], min_i[301];

int solve2(int l, int r){
    if(l == r) return l;
    int mid = (l+r+1)/2;
    cout << "? " << mid << endl;

    bool chk;
    cin >> chk;
    if(chk) return solve2(mid, r);
    else return solve2(l, mid-1);
}

int solve(int l, int r){
    if(l == r) return l;
    int mid = l + min_i[r-l+1];
    cout << "? " << mid << endl;

    bool chk;
    cin >> chk;
    if(chk){
        cout << "? " << mid << endl;
        cin >> chk;
        if(chk) return solve(mid, r);
        else return solve2(l, mid-1);
    }
    else return solve(l, mid-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=2; i<=300; i++){
        t[i] = INF;
        for(int j=1; j<=i-1; j++){
            int res = max(t[j]+1, t[i-j]+2);
            res = max(res, (int)ceil(log2(j)) + 2);
            if(res < t[i]){
                t[i] = res;
                min_i[i]= j;
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int ans = solve(2100, 2399);
        cout << "! " << ans << endl;
    }
    return 0;
}