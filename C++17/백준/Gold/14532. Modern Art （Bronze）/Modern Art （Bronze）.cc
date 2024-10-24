#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<bool> possible(10, false);

    int n;
    cin >> n;
    vector<pair<int, int>> lr(10, {n+1, -1});
    vector<pair<int, int>> ud(10, {n+1, -1});
    vector<vector<int>> board(n, vector<int>(n));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            board[i][j] = s[j] - '0';
            int num = board[i][j];
            possible[num] = true; 
            lr[num].X = min(lr[num].X, j);
            lr[num].Y = max(lr[num].Y, j);
            ud[num].X = min(ud[num].X, i);
            ud[num].Y = max(ud[num].Y, i);
        }
    }

    for(int num=1; num<=9; num++){
        for(int i=ud[num].X; i<=ud[num].Y; i++){
            for(int j=lr[num].X; j<=lr[num].Y; j++){
                if(board[i][j] != num) possible[board[i][j]] = false;
            }
        }
    }
    
    int cnt = 0;
    for(int i=1; i<=9; i++){
        if(possible[i]) cnt++;
    }

    cout << cnt;

    return 0;
}