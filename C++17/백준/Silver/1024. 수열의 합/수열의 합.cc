#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    for(int p=l; p<=100; p++){
        if((2*n)%p == 0){
            int q = 2*n/p;
            int a = (q-p+1)/2;
            int b = (q+p-1)/2;
            if(p%2 != q%2 && a >= 0){
                for(int i=a; i<=b; i++) cout << i << ' ';
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}