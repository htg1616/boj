#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    deque<int> v;
    for(int i=1; i<=n; i++) v.push_back(i);


    int ans = 0;
    for(int i=0; i<m; i++){
        int p;
        cin >> p;
        int cnt = 0;
        for(; v[cnt] != p; cnt++);

        if(cnt <= v.size()-cnt){
            ans += cnt;
            while(cnt--){
                v.push_back(v.front());
                v.pop_front();
            }   
            v.pop_front();
        }
        else{
            ans += v.size()-cnt;
            int t = v.size()-cnt;
            while(t--){
                v.push_front(v.back());
                v.pop_back();
            }
            v.pop_front();
        }
    }

    cout << ans << endl;

    return 0;
}