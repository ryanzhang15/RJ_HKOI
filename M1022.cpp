#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
constant mod1 = 51203451;
constant mod2 = 53000029;
constant big = 1E9+2;

_ n, w, h, a[maxn][2], s, b, c, d;
bitset<mod2> v1, v2;

inline _ pmod(_ x, _ md);
inline _ read();
int main() {
    
    scanf("%lld%lld%lld", &n, &w, &h);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
        c = a[i][0]*big+a[i][1];
        v1[pmod(c, mod1)] = v2[pmod(c, mod2)] = true;
    }
    for(_ i = 1; i <= n; ++i) {
        if(a[i][0]+w >= big || a[i][1]+h >= big) continue;
        b = (a[i][0]+w)*big+a[i][1], c = a[i][0]*big+a[i][1]+h, d = (a[i][0]+w)*big+a[i][1]+h;
        if(v1[pmod(b, mod1)] & v1[pmod(c, mod1)] & v1[pmod(d, mod1)] & v2[pmod(b, mod2)] & v2[pmod(c, mod2)] & v2[pmod(d, mod2)]) ++s;
    }
    printf("%lld\n", s);
    
    return 0;
}

inline _ read() {
    _ x = 0, f = 1; char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<3)+(x<<1)+ch-'0';
    return x*f;
}

inline _ pmod(_ x, _ md) {
    return (x%md+md)%md;
}
