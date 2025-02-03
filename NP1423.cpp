#include <bits/stdc++.h>
#define ef else if

typedef long long _;
typedef const long long constant;

constant mod = 1E9+7;
constant smod = 1E4+7;
constant maxo = 1E6+8;
constant maxn = 1E2+8;

_ n, m, o[maxo], a[maxn], b[maxn], c, s;
bool v[smod];

inline bool ok(_ x, _ m, _ *a);
inline void write(_ x);
inline _ read();
int main() {
    
    freopen("equation.in", "r", stdin);
    freopen("equation.out", "w", stdout);
    
    n = read();
    m = read();
    for(_ i = 0; i <= n; ++i) {
        _ ca = 0, cb = 0;
        _ f = 1; char ch = getchar_unlocked();
        for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f = -1;
        for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) {
            ca = ((ca<<3)+(ca<<1)+(ch^48))%smod;
            cb = ((cb<<3)+(cb<<1)+(ch^48))%mod;
        }
        a[i] = ca*f;
        b[i] = cb*f;
    }
    for(_ i = 0; i < smod; ++i) if(ok(i, smod, a)) v[i] = true;
    for(_ i = 1; i <= m; ++i) if(v[i%smod] && ok(i, mod, b)) o[++c] = i;
    write(c);
    putchar_unlocked(10);
    for(_ i = 1; i <= c; ++i, putchar_unlocked(10)) write(o[i]);
    
    return 0;
}

inline _ read() {
    _ x = 0, f = 1; char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = ((x<<3)+(x<<1)+(ch^48));
    return x*f;
}

inline void write(_ x) {
    if(x & (1LL<<63)) {
        putchar_unlocked('-');
        x = -x;
    }
    if(x>9) write(x/10);
    putchar_unlocked('0'+x%10);
    return;
}

inline bool ok(_ x, _ m, _ *a) {
    s = a[n];
    for(_ i = n-1; i >= 0; --i) s = (s*x+a[i])%m;
    return !s;
}

