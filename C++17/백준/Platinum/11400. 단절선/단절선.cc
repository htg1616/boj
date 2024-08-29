#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

vector<int> adj[100001];
vector<pair<int, int>> cut_edges;
int v, e, discover[100001], counter, k;

//now가 root인 subtree에서 
//트리 간선이 아닌 간선을 통해 도달할 수 있는 가장 높은 부모
int dfs(int now, int parent){
    int ret = discover[now] = counter++;

    for(int nxt: adj[now]){
        if(discover[nxt] == -1){
            int subtree = dfs(nxt, now);
            ret = min(ret, subtree);
        }
        else if(nxt != parent){
            ret = min(ret, discover[nxt]);
        }
    }

    if(ret > discover[parent]){
        if(now < parent)
            cut_edges.push_back({now, parent});
        else
            cut_edges.push_back({parent, now});
        k++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(discover, 100001, -1);
    discover[0] = 123456789;
    dfs(1, 0);

    cout << k << endl;
    sort(cut_edges.begin(), cut_edges.end());
    for(int i=0; i<k; i++){
        cout << cut_edges[i].X << ' ' << cut_edges[i].Y << endl;
    }
    return 0;
}