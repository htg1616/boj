#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
typedef long long ll;
using namespace std;
const double PI = 2.0 * acos(0.0);

struct vector2{
    double x, y;

    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_)
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

    vector2 operator * (double rhs) const{
        return vector2(x * rhs, y * rhs);
    }

    double norm() const {return hypot(x, y); }

    vector2 normalize() const{
        return vector2(x / norm(), y / norm());
    }

    double polar() const { return fmod(atan2(y, x) + 2*PI, 2*PI); }

    double dot(const vector2& rhs) const{
        return x * rhs.y - rhs.x * y;
    }

    double cross(const vector2& rhs) const{
        return x * rhs.y - rhs.x * y;
    }

    vector2 project(const vector2& rhs) const{
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};

double ccw(vector2 a, vector2 b){
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a-p, b-p);
}


vector<int> a;
vector<int> index2;

bool check(){
    for(int t=0; t<8; t++){
        vector2 p = vector2(a[index2[t]],  0);
        vector2 p1 = vector2(a[index2[(t+1)%8]] * cos(PI/4), a[index2[(t+1)%8]] * cos(PI/4));
        vector2 p2 = vector2(0, a[index2[(t+2)%8]]);
        if (ccw(p, p1, p2) < 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<8; i++){
        int x;
        cin >> x;
        a.push_back(x);
        index2.push_back(i);
    }

    int ans = 0;
    do{
        if(check()) ans++;
    }while(next_permutation(index2.begin(), index2.end()));

    cout << ans;
    return 0;
}