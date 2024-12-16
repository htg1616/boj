#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; string s;
    cin >> n >> s;
    int ans = 1e9;
    for(int i=1; i<=n; i++){
        set<int> sex;
        int cnt=0;
        for(int j=0; j<n; j++){
            if(s[j] == '#' && !sex.count(j%i)){
                cnt++;
                sex.insert(j%i);
            }
            else if(s[j] == '.' && sex.count(j%i))
                sex.erase(j%i);
        }

        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}