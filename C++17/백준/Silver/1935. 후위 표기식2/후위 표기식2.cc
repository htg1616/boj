#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    string input;
    cin >> n >> input;
    vector<int> numbers(n);
    for(int& i : numbers){
        cin >> i;
    }

    vector<double> stack;
    for(char i : input){
        if('A'<= i && i <= 'Z'){
            stack.push_back(numbers[i-'A']);
        }
        else{
            double back2 = stack.back();
            stack.pop_back();
            double back1 = stack.back();
            stack.pop_back();
            if(i=='+') stack.push_back(back1 + back2);
            else if(i=='-') stack.push_back(back1 - back2);
            else if(i=='*') stack.push_back(back1 * back2);
            else if(i=='/') stack.push_back(back1 / back2);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << stack[0];
    return 0;
}