#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;

vector<int> error_button;

bool isavail(int num){
    if(num == 0){
        if(count(error_button.begin(), error_button.end(), 0) >= 1) return false;
        return true;
    }
    while(num > 0){
        if(count(error_button.begin(), error_button.end(), num%10) >= 1) return false;
        num = num / 10;
    }
    return true;
}

int lenint(int num){
    if(num == 0) return 1;
    int l = 0;
    while(num > 0){
        num = num / 10;
        l++;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;

    cin >> n >> m;
    FOR(i, m){
        int error;
        cin >> error;
        error_button.push_back(error);
    }

    int max_dist = abs(100 - n);
    for(int num = 0; num <= 1'000'000; num++){
        if(isavail(num)){
            int dist = abs(num - n) + lenint(num);
            if(dist < max_dist) max_dist = dist;
        }
    }
    cout << max_dist;
    return 0;
}