#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, tmax;
    cin >> n >> tmax;
    vector<int> d(n);
    for(int i=0; i<n; i++) cin >> d[i];

    auto check = [&](int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            if(pq.size()< k) pq.push(d[i]);
            else if(pq.size() == k){
                int t = pq.top();
                pq.pop();
                pq.push(t+d[i]);
            }
        }

        ll time = 0;
        while(!pq.empty()){
            time = pq.top();
            pq.pop(); 
        }

        return time <= tmax;
    };

    int l = 0, r = n;
    while(l < r){
        int mid = l + (r - l)/2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r << endl;
    return 0;
}