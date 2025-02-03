#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ N, H, a[maxn], cnt;

inline void o(_ n, _ h, _ s);
int main() {
    
    scanf("%lld%lld", &N, &H);
    o(N, H, 0);
    for(_ i = 1; i <= cnt; ++i) printf("%lld ", a[i]);
    putchar(10);
    
    return 0;
}

inline void o(_ n, _ h, _ s) {
    if(!n) return;
    if((1<<(h-1)) < n-(1<<(h-1))+1) {
        puts("0");
        exit(0);
    }
    a[++cnt] = max((_)1+s, n-(1<<(h-1))+1+s);
    _ sv = cnt;
    o(a[sv]-1-s, h-1, s);
    o(n-a[sv]+s, h-1, a[sv]);
    return;
}
