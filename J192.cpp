#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E5+8;
_ n, k, a[maxn], p[maxn], s = -1E18, x;

inline void write(_ x);
inline _ read();
int main() {
    
    n = read();
    k = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    sort(a+1, a+1+n);
    for(_ i = 1; i <= n; ++i) p[i] = a[i]+p[i-1];
    if(k & 1) {
        for(_ i = (k>>1)+1; i + (k>>1) <= n; ++i) {
            _ o = a[i]*(k-1) - (p[k>>1] + p[i+(k>>1)] - p[i]);
            if(o > s) {
                s = o;
                x = i;
            }
        }
        for(_ i = 1; i <= (k>>1); ++i) write(a[i]);
        for(_ i = x; i <= x+(k>>1); ++i) write(a[i]);
    } else {
        for(_ i = (k>>1)+1; i + (k>>1) - 1 <= n; ++i) {
            _ o = ((k>>1)-1)*(a[i-1]+a[i]) - (p[(k>>1)-1] + p[i+(k>>1)-1] - p[i]);
            if(o > s) {
                s = o;
                x = i;
            }
        }
        for(_ i = 1; i <= (k>>1)-1; ++i) write(a[i]);
        for(_ i = x-1; i <= x+(k>>1)-1; ++i) write(a[i]);
    }
    putchar(10);
    
    return 0;
}

inline _ read() {
    _ x = 0; char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+ch-48;
    return x;
}

inline void write(_ x) {
    _ cnt;
    char bf[10];
    for(; x; x /= 10) bf[++cnt] = 48+x%10;
    for(_ i = cnt; i >= 1; --i) putchar_unlocked(bf[i]);
    putchar_unlocked(32);
    return;
}

