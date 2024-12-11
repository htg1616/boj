#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

constexpr int MAX_N = 100'000;
int field[1+MAX_N], cnt[1+MAX_N];

int count(int n){
    if(n == 1) return 0;
    if(cnt[n] != 0) return cnt[n];
    return cnt[n] = 1+count(n/field[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(field, 1+MAX_N, 1);
    for(int i=2; i<=MAX_N; i++){
        if(field[i] == 1){
            for(int j=i; j<=MAX_N; j+=i){
                if(field[j] == 1) field[j] = i;
            }
        }
    }

    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i=a; i<=b; i++){
        int p = count(i);
        if(p != 1 && field[p] == p) ans++;
    }
    cout << ans;
    return 0;
}