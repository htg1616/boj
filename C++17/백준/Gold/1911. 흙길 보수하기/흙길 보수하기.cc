#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n, l;
pair<int, int> pos[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        pos[i] = {a, b};
    }
    sort(pos, pos+n);

    int cnt = 0;
    int rp = -1;
    for(int i=0; i<n; i++){
        int x = pos[i].X;
        int y = pos[i].Y;
        while(y-1 > rp){
            cnt++;
            rp = max(x+l-1, rp+l);
        }
    }
    cout << cnt;
    return 0;
}