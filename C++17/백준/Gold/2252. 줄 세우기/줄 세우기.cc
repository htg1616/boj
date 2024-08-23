#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n, m;
vector<int> adj[40000];
int degree[40000];

void top_sort(){
    queue<int> q;
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for(int next: adj[now]){
            if(--degree[next] == 0)
                q.push(next);
        }
    }
    for(int node: ans){
        cout << node << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b]++;
    }
    
    top_sort();
    return 0;
}