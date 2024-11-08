#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

bool valid(int num){
    int a = num/100, b = num/10%10, c = num%10;
    if(a==0 ||  b==0 || c==0) return false;
    return (a != b) && (b != c) && (c != a);
}

int strike(int ans, int stand){
    int ret = 0;
    for(int i=1; i<=100; i*=10){
        if(ans/i%10 == stand/i%10) ret++;
    }

    return ret;
}

int ball(int ans, int stand){
    int ret = 0;
    for(int i=1; i<=100; i*=10){
        for(int j=1; j<=100; j*=10){
            if(i==j) continue;
            if(ans/i%10 == stand/j%10) ret++;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n), arr_strike(n), arr_ball(n);
    for(int i=0; i<n; i++){
        cin >> nums[i] >> arr_strike[i] >> arr_ball[i];
    }

    int ans = 0;
    for(int i=100; i<=999; i++){
        if(!valid(i)) continue;
        bool chk = true;
        for(int j=0; j<n; j++){
            if(strike(i, nums[j]) != arr_strike[j]) chk = false;
            if(ball(i, nums[j]) != arr_ball[j]) chk = false;
        }
        if(chk) ans++;
    }

    cout << ans;
    return 0;
}