#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> a;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }

    int ans = 0;
    for(int choose = 1; choose < (1<<n); choose++){
        int s = 0, cnt = 0, hard = -1, easy = 1<<20;
        for(int i=0; i<n; i++){
            if(choose & (1<<i)){
                cnt++;
                s += a[i];
                hard = max(hard, a[i]);
                easy = min(easy, a[i]);
            }
        }
        if(cnt >= 2 && l <= s && s <= r && (hard - easy) >= x){
            ans++;
        }
    }
    cout << ans;
    return 0;
}