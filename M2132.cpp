#include <bits/stdc++.h>
#define ef else if
#define i(x) x::iterator
#define mp(x, y) make_pair(x, y)
#define v(x) vector<x > 

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

typedef long long ll;

constant maxn = 1E3+8;

_ n, x, y, r, s, a[maxn][maxn], mnj = 1E11, mnk;

_D dist(_D xa, _D ya, _D xb, _D yb);
int main() {

//#define file_IO
#ifdef file_IO
    freopen("data.in", "r", stdin);
#endif

    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        _ rea = 0;
        scanf("%lld%lld%lld", &x, &y, &r);
        for(_ j = 0; j < 1000; ++j) for(_ k = 0; k < 1000; ++k) if(dist(j/100.L, k/100.L, x, y) <= r) {
            mnj = min(mnj, j);
            mnk = min(mnk, k);
            ++a[j][k];
            ++rea;
        }
        //printf("%lld %lld %lld\n", rea, mnj, mnk);
        //printf("%Lf\n", dist(mnj/100.L, mnk/100.L, 5, 5));
    }
    for(_ i = 0; i < 1000; ++i) for(_ j = 0; j < 1000; ++j) if(a[i][j] == n) ++s;
    printf("%Lf\n", s/10000.L);
    
    
    return 0;
}

_D dist(_D xa, _D ya, _D xb, _D yb) {
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}