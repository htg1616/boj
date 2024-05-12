#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int arr[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
        }
    }
    int max_i = 0;
    int max_j = 0;
    for(int i =0; i<9; i++){
        for(int j=0; j<9; j++){
            if (arr[i][j] > arr[max_i][max_j]){
                max_i = i;
                max_j = j;
            }
        }
    }
    cout << arr[max_i][max_j] << endl;
    cout << max_i+1 << ' ' << max_j+1 << endl;
    return 0;
}