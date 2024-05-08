#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> a(4);
    for (int i=0; i<4; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[0] * a[2];
    return 0;
}