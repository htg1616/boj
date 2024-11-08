#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int visible(vector<int> arr){
    int max_h = 0, ret = 0;
    for(int i: arr){
        if(i > max_h) ret++;
        max_h = max(max_h, i);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    cout << visible(h) << endl;
    reverse(begin(h), end(h));
    cout << visible(h) << endl;
    return 0;
}