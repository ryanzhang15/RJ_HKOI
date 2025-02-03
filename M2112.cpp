
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef pair<_, _> _p;
typedef const long long constant;

inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline void AC();
int main() {
    
//#define MULTIPLE_TESTCASES
#ifdef MULTIPLE_TESTCASES
    _ tc = read();
    for(; tc--; ) AC();
#else
    AC();
#endif
    
    return 0;
}



// ------ separation line ------



constant maxn = 4E5+8;

_ n, x, a[maxn], p[maxn], ad;

_ binSearchR(_ c, _ t);
_ binSearchL(_ c, _ t);
inline void AC() {
    
    n = read();
    x = read();
    for(_ i = 1; i <= n; ++i) p[i] = p[i-1] + (a[i] = read());
    for(_ i = 1; i <= n; ++i) if(a[i] <= x) {
        _ p1 = i, p2 = i, c = a[i]+x;
        for(;;) {
            if(p1 > 1) {
                p1 = binSearchL(p1, c);
                c += ad;
            }
            if(p2 < n) {
                p2 = binSearchR(p2, c);
                c += ad;
            }
            if(p1 == 1 && p2 == n) break;
            bool ok = false;
            if(p1 > 1 && a[p1-1] <= c) {
                c += a[p1-1];
                --p1;
                ok = true;
            }
            if(p2 < n && a[p2+1] <= c) {
                c += a[p2+1];
                ++p2;
                ok = true;
            }
            if(!ok) break;
        }
        if(p1 == 1 && p2 == n) {
            printf("%lld ", i);
            _ p1 = i-1, p2 = i+1, c = a[i]+x;
            for(; p1 > 0 || p2 <= n; ) {
                bool ok = false;
                if(p1 > 0 && a[p1] <= c) {
                    ok = true;
                    printf("%lld ", p1);
                    c += a[p1];
                    --p1;
                }
                if(p2 <= n && a[p2] <= c) {
                    ok = true;
                    printf("%lld ", p2);
                    c += a[p2];
                    ++p2;
                }
                if(!ok) break;
            }
            putchar(10);
            exit(0);
        }
    }
    puts("Impossible");
    
    return;
}

_ binSearchL(_ c, _ t) {
    _ l = 1, r = c, md, s = -1;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(p[c-1]-p[md-1] <= t) {
            s = md;
            ad = p[c-1]-p[md-1];
            r = md-1;
        } else l = md+1;
    }
    return s;
}

_ binSearchR(_ c, _ t) {
    _ l = c, r = n, md, s = -1;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(p[md]-p[c] <= t) {
            s = md;
            ad = p[md]-p[c];
            l = md+1;
        } else r = md-1;
    }
    return s;
}
