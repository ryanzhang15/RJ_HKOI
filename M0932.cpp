#include <bits/stdc++.h>
#define ef else if

typedef long long _;
typedef const long long constant;

constant maxn = 5E5+8;
constant mod = 2000000011;
constant mul = 29;

_ n, s, t, p;
char a[maxn], b[maxn];
bool o;

inline _ power(_ x);
inline void in(char * a);
int main() {
    
    in(a);
    in(b);
    for(_ i = 0; i < n; ++i) s = (s*mul+a[i])%mod;
    for(_ i = 0; i < n; ++i) t = (t*mul+b[i])%mod;
    p = power(n-1);
    for(_ i = 0; i < n-1; ++i) {
        s = ((((s-(p*a[i]))%mod+mod)%mod)*mul+a[i])%mod;
        if(s == t) {
            printf("%lld\n", i+1);
            o = true;
        }
    }
    
    if(!o) puts("-1");
    
    return 0;
}

inline void in(char * a) {
    register char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar_unlocked();
    for(n = 0; ch >= 'A' && ch <= 'Z'; ++n, ch = getchar_unlocked()) a[n] = ch;
    return;
}

inline _ power(_ x) {
    if(!x) return 1;
    _ c = power(x>>1);
    if(x & 1) return ((c*c)%mod*mul)%mod;
    else return (c*c)%mod;
}
