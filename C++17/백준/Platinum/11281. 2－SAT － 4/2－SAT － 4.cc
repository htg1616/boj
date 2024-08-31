#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int n, m, discover[20001], sccid[20001], counter, scc_counter;
vector<int> adj[20001]; //i에 대해 n+i는 참을, n-i는 거짓을 나타냄
stack<int> st;

int tarjan(int now){
    int ret = discover[now] = counter++;

    st.push(now);
    for(int nxt: adj[now]){
        if(discover[nxt] == -1)
            ret = min(ret, tarjan(nxt));
        else if(sccid[nxt] == -1)
            ret = min(ret, discover[nxt]);
    }

    if(discover[now] == ret){
        while(true){
            int t = st.top();
            st.pop();
            sccid[t] = scc_counter;
            if(t == now) break;
        }
        scc_counter++;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[n-a].push_back(b+n);
        adj[n-b].push_back(a+n);
    }
    fill_n(discover, 20001, -1);
    fill_n(sccid, 20001, -1);

    for(int i=0; i<=2*n; i++){
        if(i == n) continue;
        if(discover[i] == -1) tarjan(i);
    }

    bool is_ans = true;
    for(int i=1; i<=n; i++){
        if(sccid[n-i] == sccid[n+i])
            is_ans = false;
    }

    //정답 출력
    if(!is_ans){
        cout << 0;
        return 0;
    }
    cout << 1 << endl;
    int ans[10001];
    fill_n(ans, 10001, -1);

    vector<pair<int, int>> sat_order;
    for(int i=0; i<=2*n; i++){
        if(i == n) continue;
        sat_order.push_back({sccid[i], i});
    }
    sort(sat_order.begin(), sat_order.end());
    for(auto p: sat_order){
        int vertex = abs(p.Y-n);
        bool istrue = p.Y > n;
        if(ans[vertex] != -1) continue;
        ans[vertex] = istrue;
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}