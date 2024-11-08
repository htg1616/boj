#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> nums(9);
    for(int i=0; i<9; i++){
        cin >> nums[i];
    }

    int sum = accumulate(begin(nums), end(nums), 0);
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if((sum - nums[i] - nums[j]) != 100) continue;
            for(int k=0; k<9; k++){
                if(k != i && k != j) cout << nums[k] << endl;
            }
        }
    }
    return 0;
}