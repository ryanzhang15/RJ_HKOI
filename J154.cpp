#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, h[maxn], s, p = 2, a, b, c;

inline _ read();
int main() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) h[i] = read();
    m += h[1];
    for(;;) {
        for(; p <= n && h[p] <= m; ) ++p;
        if(p > n) {
            if(m + h[1] >= h[n]<<1 && s) --s;
            printf("%lld\n", s);
            exit(0);
        }
        a = h[p]-m;
        b = (h[p-1]-h[1])<<1;
        if(!b) {
            puts("Impossible");
            exit(0);
        }
        c = (a-1)/b+1;
        s += c<<2;
        m += b*c;
    }
    
    return 0;
}

inline _ read() {
    _ x = 0; char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+ch-48;
    return x;
}
