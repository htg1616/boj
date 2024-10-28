#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int is_palindrome_dp[2510][2510], min_partition_dp[2510];
int n;
string s;

int is_palindrome(int l, int r){ //s[i, j)가 펠린드롬인지 판별
    if((r-l) <= 1) return true;
    int &ret = is_palindrome_dp[l][r];
    if(ret != -1) return ret;
    ret = s[l] == s[r-1] && is_palindrome(l+1, r-1) ;
    return ret;
}

int min_partition(int i){
    if(i == n) return 0;
    int &ret = min_partition_dp[i];
    if(ret != 123456789) return ret;
    for(int j=i+1; j<=n; j++){
        if(is_palindrome(i, j)) ret = min(ret, min_partition(j)+1);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(is_palindrome_dp[0], 2510*2510, -1);
    fill_n(min_partition_dp, 2510, 123456789);

    cin >> s;
    n = s.length();
    cout << min_partition(0);
    return 0;
}