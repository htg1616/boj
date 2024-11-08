#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, t; bool flag;
    cin >> a >> t >> flag;
    int cnt = 0;
    for(int i=2; ; i++){
        array<int, 3> term = {1, 1, i};
        for(int time: term){
            array<bool, 2> check = {false, true};
            for(bool chk: check){
                for(int k=0; k<time; k++){
                    if(chk == flag){
                        t--;
                        if(t == 0){
                            cout << cnt;
                            return 0;
                        }
                    }
                    cnt = (cnt+1)%a;
                }
            }
        }
    }
    return 0;
}