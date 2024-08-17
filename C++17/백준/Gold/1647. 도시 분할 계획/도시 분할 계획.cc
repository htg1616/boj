#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

int parent[100001];

int find(int u)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v)
{
    int root1 = find(u);
    int root2 = find(v);
    if(root1 != root2){
        parent[root1] = root2;
        //TLE시 rank 추가필요
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());
    int cnt = 0;
    int cost = 0;
    for(auto x: edges){
        if(cnt == n-2) break;
        int c = x.X;
        int a = x.Y.X;
        int b = x.Y.Y;
        if(find(a) != find(b)){
            merge(a, b);
            cnt++;
            cost += c;
        }
    }
    cout << cost;
    return 0;
}