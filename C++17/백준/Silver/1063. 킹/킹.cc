#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x1, y1, x2, y2, n;
    string s1, s2;
    cin >> s1 >> s2 >> n;
    x1 = s1[0] - 'A';
    y1 = s1[1] - '1';
    x2 = s2[0] - 'A';
    y2 = s2[1] - '1';

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int x=0, y=0, xx=0, yy=0;
        if(s.find("R") != string::npos){
            x = 1;
        }
        if(s.find("L") != string::npos){
            x = -1;
        }
        if(s.find("B") != string::npos){
            y = -1;
        }
        if(s.find("T") != string::npos){
            y = 1;
        }

        if(x1 + x == x2 && y1+y == y2){
            xx=x;
            yy=y;
        }
        if(0<= x1+x && x1+x < 8 && 0<= y1+y && y1+y < 8 &&
           0 <= x2+xx && x2+xx < 8 && 0 <= y2+yy && y2+yy < 8){
            x1 += x;
            y1 += y;
            x2 += xx;
            y2 += yy;
        }
    }

    cout << char('A'+x1) << y1+1 << endl;
    cout << char('A'+x2) << y2+1 << endl;
    return 0;
}