#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;

pair<int, int> child[10001];
vector<int> h[10000];
int x[10001], parent[10001], n, cnt = 1, maxh = 0;

int find_root(int now){
    if(!parent[now])
        return now;
    return find_root(parent[now]);
}

void dfs(int now, int height){
    int left = child[now].X;
    int right = child[now].Y;

    if(left != -1){
        dfs(left, height + 1);
    }

    x[now] = cnt++;
    h[height].push_back(x[now]);
    maxh = max(maxh, height);

    if(right != -1){
        dfs(right, height+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        child[a] = {b, c};
        parent[b] = a;
        parent[c] = a;
    }
    int root = find_root(1);
    dfs(root, 1);
    int maxd = 0, maxd_h;
    for(int i=1; i<= maxh; i++){
        sort(h[i].begin(), h[i].end());
        int d = h[i].back() - h[i].front() + 1;
        if(d > maxd){
            maxd = d;
            maxd_h = i;
        }
    }
    
    cout << maxd_h << ' ' << maxd;
    return 0;
}