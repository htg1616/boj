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
    priority_queue<int> big;
    priority_queue<int, vector<int>, greater<int>> small;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        if(big.size() > small.size()){
            big.push(p);
            small.push(big.top());
            big.pop();
        }
        else{
            small.push(p);
            big.push(small.top());
            small.pop();
        }
        cout << big.top() << endl;
    }
    return 0;
}