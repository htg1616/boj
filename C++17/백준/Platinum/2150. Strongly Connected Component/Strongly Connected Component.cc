#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int v, e, discover[10001], counter;
bool isscc[10001];
vector<int> adj[10001], st;
vector<vector<int>> scc_comp;

int scc(int now){
    int ret = discover[now] = counter++;

    st.push_back(now);
    for(int nxt: adj[now]){
        if(discover[nxt] == -1)
            ret = min(ret, scc(nxt));
        else if(!isscc[nxt])
            ret = min(ret, discover[nxt]);
    }

    if(ret == discover[now]){
        vector<int> new_scc;
        while(true){
            int t = st.back();
            st.pop_back();
            isscc[t] = true;
            new_scc.push_back(t);
            if(t == now)
                break;
        }
        scc_comp.push_back(new_scc);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(discover, 10001, -1);
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1; i<=v; i++){
        if(discover[i] == -1)
            scc(i);
    }
    for(vector<int> &i: scc_comp){
        sort(i.begin(), i.end());
    }
    sort(scc_comp.begin(), scc_comp.end());
    cout << scc_comp.size() << endl;
    for(auto i: scc_comp){
        for(int j: i){
            cout << j << ' ';
        }
        cout << -1 << endl;
    }
    return 0;
}