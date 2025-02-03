
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant big = 1E12;
constant maxn = 5E5+8;

_ n, m, l, r = big-1, md, c[maxn];
_p s = mp(1, 1);

bool check(_ x);
bool cmp(_p a, _p b);
_ gcd(_ a, _ b);
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(check(md)) l = md+1;
        else r = md-1;
    }
    printf("%lld/%lld\n", s.first, s.second);
    
    return 0;
}

_ gcd(_ a, _ b) {
    return !b ? a : gcd(b, a%b);
}

bool cmp(_p a, _p b) {
    return a.first*b.second < b.first*a.second;
}

bool check(_ x) {
    for(_ i = 1; i <= n; ++i) c[i] = i*x/big;
    for(_ i = 1; i <= n; ++i) for(_ j = i+i; j <= n; j += i) c[j] -= c[i];
    _ s = 1;
    for(_ i = 1; i <= n; ++i) s += c[i];
    if(s == m) {
//        printf("%lld\n", x);
        _p cr = mp(0, 0);
        _D bd = 1E11;
        for(_ i = 1; i <= n; ++i) {
            _ a = x*i/big;
            if(abs(1.L*a/i-1.L*x/big) < bd) {
                bd = abs(1.L*a/i-1.L*x/big);
                cr = mp(a, i);
            }
        }
        ::s = cr;
    }
    return s < m;
}

