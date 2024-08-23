#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;
const double PI = 2.0 * acos(0.0);

struct vector2{
    ll x, y;

    explicit vector2(ll x_ = 0, ll y_ = 0) : x(x_), y(y_)
    {}

    bool operator == (const vector2 &rhs) const{
        return x == rhs.x && y == rhs.y;
    }

    bool operator < (const vector2 &rhs) const{
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }

    vector2 operator + (const vector2 &rhs) const{
        return vector2(x + rhs.x, y + rhs.y);
    }

    vector2 operator - (const vector2 &rhs) const{
        return vector2(x - rhs.x, y - rhs.y);
    }

    vector2 operator * (ll rhs) const{
        return vector2(x * rhs, y * rhs);
    }

    ll dot(const vector2& rhs) const{
        return x * rhs.y - rhs.x * y;
    }

    ll cross(const vector2& rhs) const{
        return x * rhs.y - rhs.x * y;
    }

};

ll ccw(vector2 a, vector2 b){
    return a.cross(b);
}

ll ccw_sign(vector2 p, vector2 a, vector2 b){
    ll val = ccw(a-p, b-p);
    if(val > 0) return 1;
    else if(val == 0) return 0;
    else return -1;
}

bool segmentllersects(vector2 a, vector2 b, vector2 c, vector2 d){
    ll ab = ccw_sign(a, b, c) * ccw_sign(a, b, d);
    ll cd = ccw_sign(c, d, a) * ccw_sign(c, d, b);
    if(ab==0 && cd==0){
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    vector2 a(x1, y1), b(x2, y2);
    vector2 c(x3, y3), d(x4, y4);

    if(segmentllersects(a, b, c, d))
        cout << 1;
    else
        cout << 0;
    return 0;
}