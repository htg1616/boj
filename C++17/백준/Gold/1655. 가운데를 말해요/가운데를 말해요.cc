#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        if(max_pq.size() > min_pq.size()){
            max_pq.push(p);
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else{
            min_pq.push(p);
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        cout << max_pq.top() << endl;
    }
    return 0;
}