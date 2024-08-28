#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

vector<int> adj[10001];
int discoverd[10001], counter, iscut[10001];

int find_cut(int now, bool isroot){
    discoverd[now] = counter++;
    int ret = discoverd[now];

    int child = 0;
    for(int nxt: adj[now]){
        if(discoverd[nxt] == -1){
            child++;
            int subtree = find_cut(nxt, false);

            if(!isroot && subtree >= discoverd[now]){
                iscut[now] = true;
            }
            else
                ret = min(ret, subtree);
        }
        else
            ret = min(ret, discoverd[nxt]);
    }
    if(isroot && child>=2){
        iscut[now] = true;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(discoverd, 10001, -1);

    for(int i=1; i<=v; i++){
        if(discoverd[i] == -1)
            find_cut(i, true);
    }

    int cut_cnt = 0;
    for(int i=1; i<=v; i++){
        if(iscut[i]) cut_cnt++;
    }

    cout << cut_cnt << endl;
    for(int i=1; i<=v; i++){
        if(iscut[i]) cout << i << ' ';
    }
    return 0;
}