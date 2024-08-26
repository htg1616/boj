#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

vector<int> arr;
int fpr[5'000'001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    fpr[1] = 1;
    for(int i=2; i <= 5'000'000; i++){
        if(fpr[i]){
            continue;
        }
        fpr[i] = i;
            if(i < 30000)
            for(int j = i*i; j<= 5'000'000; j+=i){
                if(!fpr[j]) fpr[j] = i;
            }
    }

    for(int n: arr){
        while(n > 1){
            cout << fpr[n] << ' ';
            n /= fpr[n];
        }
        cout << endl;
    }
    return 0;
}