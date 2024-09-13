#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int score(vector<int> four){
    sort(four.begin(), four.end());

    if(four[0] == four[3])
        return 50000 + four[0]*5000;
    if(four[0] == four[2] || four[1] == four[3])
        return 10000 + four[1]*1000;
    if(four[0] == four[1] && four[2] == four[3])
        return 2000 + four[0]*500 + four[2]*500;
    for(int i=0; i<3; i++){
        if(four[i] == four[i+1])
            return 1000 + four[i]*100;
    }
    return four[3]*100;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ans = max(ans, score(vector<int>{a, b, c, d}));
    }
    cout << ans;
    return 0;
}