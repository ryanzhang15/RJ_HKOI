
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
#define el else

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 5E4+8;
constant big = 1E5;
constant maxb = big+8;

_ n, m, x, q, s, b[maxb], t;
bitset<maxb> p;
struct rect {
    _ x, y;
} a[maxn];

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &x);
        p.set(x);
    }
    for(_ i = 1; i <= big; ++i) {
        if(p[i]) b[i] = i;
        else b[i] = b[i-1];
    }
    for(_ i = 1; i <= m; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
    scanf("%lld", &q);
    for(; q--; ) {
        scanf("%lld", &x);
        s = 0;
        for(_ i = 1; i <= m; ++i) {
            t = min((x-(a[i].x<<1))>>2, big);
            if(t >= 0 && b[t] > a[i].y) s = max(s, b[t]*b[t] + a[i].x*a[i].y);
            t = min(a[i].y, (x-(a[i].x<<1)-(a[i].y<<1))>>1);
            t = min(t, big);
            if(t >= 0 && b[t]) s = max(s, b[t]*b[t] + a[i].x*a[i].y);
        }
        printf("%lld\n", s);
    }
    return 0;
}

