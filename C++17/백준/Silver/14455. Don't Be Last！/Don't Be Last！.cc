#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<string, int> cows;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string name; int milk;
        cin >> name >> milk;
        cows[name] += milk;
    }

    int min_milk = 123456789;
    for(auto cow: cows){
        min_milk = min(min_milk, cow.Y);
    }
    if(cows.size() < 7) min_milk = 0;

    string min_cow = "Tie";
    int min_milk2 = 123456789;
    for(auto cow: cows){
        if(cow.Y > min_milk){
            if(cow.Y == min_milk2){
                min_cow = "Tie";
            }
            else if(cow.Y < min_milk2){
                min_milk2 = cow.Y;
                min_cow = cow.X;
            }
        }
    }
    cout << min_cow << endl;
    return 0;
}