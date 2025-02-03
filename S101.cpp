#include <cstdio>
#define ef else if

typedef int _;
typedef const long long constant;

constant maxn = 3E3+8;
constant maxc = 6E4+8;

_ n, m, d[maxn], p[maxn], a[maxc], b[maxc], s, x, y, t;
char c;

inline _ read();
int main() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) {
        d[i] = read();
        p[i] = read();
        c = getchar_unlocked();
        if(c == 'A') a[d[i]] = i;
        else b[d[i]] = i;
    }
    d[3001] = 1E10;
    p[3000] = 0;
    a[60000] = b[60000] = 3001;
    for(_ i = 60000; ~i; --i) {
        if(!a[i]) a[i] = a[i+1];
        if(!b[i]) b[i] = b[i+1];
    }
    for(; m--; ) {
        x = read();
        y = read();
        t = x > y ? x : y;
        if(d[a[t]] != t && d[b[x+y]] != x+y) s += d[a[t]] < d[b[x+y]] ? p[a[t]] : p[b[x+y]];
    }
    printf("%lld\n", s);
    
    return 0;
}

inline _ read() {
    _ x = 0; char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+ch-'0';
    return x;
}
