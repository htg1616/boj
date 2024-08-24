#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n, k;
int arr[10000];
vector<int> seg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    int len = arr[n-1] - arr[0];
    for(int i=0; i<n-1; i++){
        int d = arr[i+1] - arr[i];
        if(d != 0)
            seg.push_back(d);
    }
    sort(seg.begin(), seg.end());
    reverse(seg.begin(), seg.end());

    for(int i=0; i< min(int(seg.size()), k-1); i++){
        len -= seg[i];
    }
    cout << len;
    return 0;
}