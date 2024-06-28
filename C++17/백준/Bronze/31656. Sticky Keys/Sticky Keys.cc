#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin, s);
    
    cout << s[0];
    for(int i=1; i<s.length(); i++){
        if(s[i] != s[i-1]) cout << s[i];
    }

    return 0;
}