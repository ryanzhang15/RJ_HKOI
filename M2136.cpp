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

constant maxn = 16+8;

_ n, m, s = 1E17, a[maxn], b[maxn];
bitset<maxn> v;

inline void dfs(_ x, _ l, _ y);
int main() {

//#define file_IO
#ifdef file_IO
    freopen("data.in", "r", stdin);
#endif

    scanf("%lld%lld", &n, &m);
    b[0] = 1;
    for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &a[i], &b[i]);
    dfs(1, 0, 0);
    printf("%lld\n", s);
    
    return 0;
}

inline void dfs(_ x, _ l, _ y) {
    if(y >= s) return;
    if(x > n) {
        s = y;
        return;
    }
    for(_ i = 1; i <= n; ++i) if(!v[i]) {
        v.set(i);
        dfs(x+1, i, y+(x*b[l]%m*a[i])%m);
        v.reset(i);
    }
    return;
}