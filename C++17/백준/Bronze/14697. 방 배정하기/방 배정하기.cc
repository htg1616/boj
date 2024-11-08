#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c, n;
    cin >> a >> b >> c >> n;
    bool chk = false;
    for(int i=0; i<=300; i++){
        for(int j=0; j<=300; j++){
            for(int k=0; k<=300; k++){
                if((a*i+b*j+c*k) == n) chk = true;
            }
        }
    }

    cout << chk;
    return 0;
}