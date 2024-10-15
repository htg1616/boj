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
    vector<int> first(7, -1);
    first[0] = 0;
    int ans = 0;
    int curr = 0;
    for(int i=1; i<=n; i++){
        int num;
        cin >> num;
        curr = (curr + num)%7;

        if(first[curr] == -1){
            first[curr] = i;
        }
        else ans = max(ans, i - first[curr]);
    }

    cout << ans;

    return 0;
}