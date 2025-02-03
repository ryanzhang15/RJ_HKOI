
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef double _D;
typedef const long long constant;

constant maxn = 1E5+8;

struct point {
    _ x, y;
    bool operator == (const point &b) const {
        return x == b.x && y == b.y;
    }
} a[maxn];
_ gcd(_ a, _ b);
struct slope {
    _ y, x;
    void make(point a, point b) {
        y = a.y-b.y;
        x = a.x-b.x;
        _ g = gcd(y, x);
        y /= g;
        x /= g;
        if(!y) x = 0;
        return;
    }
    bool operator < (const slope &b) const {
        if(y != b.y) return y < b.y;
        return x < b.x;
    }
    bool operator == (const slope &b) const {
        return y == b.y && x == b.x;
    }
} c[maxn];
_ n, s, cnt, sc, cr, cb, p;

_ gcd(_ a, _ b);
int main() {
    
    scanf("%lld%lld", &n, &p);
    for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
    if(n == 2) {
        puts("possible");
        exit(0);
    }
    p = ceil(1.0*n*p/100.0);
    for(_ t = 1; t <= 100; ++t) {
        _ i = rand()%n+1;
        cnt = sc = cb = 0;
        cr = 1;
        for(_ j = 1; j <= n; ++j) {
            if(a[i] == a[j]) {
                ++sc;
                continue;
            }
            c[++cnt].make(a[i], a[j]);
        }
        sort(c+1, c+1+cnt);
        for(_ i = 2; i <= cnt; ++i) {
            if(c[i] == c[i-1]) ++cr;
            else cr = 1;
            cb = max(cb, cr);
        }
        if(sc+cb >= p) {
            puts("possible");
            exit(0);
        }
    }
    puts("impossible");

    return 0;
}

_ gcd(_ a, _ b) {
    if(!b) return a;
    return gcd(b, a%b);
}
