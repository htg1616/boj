#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i, N) for(int i = 0; i < N; ++i)
typedef long long ll;
using namespace std;

int n;
int post[100'001];
int in[100'001];
int index_in[100'001];
int index_post[100'001];

void preorder(int l_in, int r_in, int l_post, int r_post){
    if(r_in - l_in == 1){
        cout << in[l_in] << ' ';
        return;
    }
    else if(r_in - l_in == 0) return;

    int sep = post[r_post-1];
    int sep_in = index_in[sep];
    int len1 = sep_in - l_in;
    int len2 = r_in - sep_in - 1;

    cout << sep << ' ';
    preorder(l_in, l_in + len1, l_post, l_post + len1);
    preorder(r_in - len2, r_in, r_post - len2 - 1, r_post - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> in[i];
        index_in[in[i]] = i;
    }
    for(int i=1; i<=n; i++){
        cin >> post[i];
        index_post[post[i]] = i;
    }
    preorder(1, n+1, 1, n+1);
    return 0;
}