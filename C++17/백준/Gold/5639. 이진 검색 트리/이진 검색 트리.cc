#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

vector<int> keys;

void posto(vector<int>::iterator left, vector<int>::iterator  right){
    if(right - left == 1){
        cout << *left << endl;
        return;
    }
    if(right - left == 0)
        return;
    int parent = *left;
    auto sep = lower_bound(left+1, right, parent);

    posto(left+1, sep);
    posto(sep, right);
    cout << parent << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int key;
    while(cin >> key){
        keys.push_back(key);
    }
    posto(keys.begin(), keys.end());
    return 0;
}