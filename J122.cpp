#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, m, r, c;

int main() {
    
    scanf("%lld%lld%lld%lld", &n, &m, &r, &c);
    
    if(!((m*n) & 1) || (r-c)&1) {
        puts("Impossible");
        exit(0);
    }
    for(_ i = 1; i <= r-1; ++i) {
        for(_ j = 0; j < m-1; ++j) putchar('f'+(i%2)+(j&2));
        putchar('u'+((i-1)&2));
        putchar(10);
    }
    if(r & 1) {
        for(_ i = 0; i < c-1; ++i) putchar('c'+(i&2));
        putchar('*');
        for(_ i = c; i <= m-1; ++i) putchar('c'+((i+1)&2));
        putchar(10);
    } else {
        putchar('k'+(r&2));
        for(_ i = 0; i < c-2; ++i) putchar('c'+(i&2));
        putchar('*');
        for(_ i = c; i <= m-2; ++i) putchar('c'+(i&2));
        putchar('u'+((r-1)&2));
        putchar(10);
    }
    for(_ i = r+1; i <= n; ++i) {
        putchar('k'+(i&2));
        for(_ j = 0; j < m-1; ++j) putchar('f'+(i%2)+(j&2));
        putchar(10);
    }
    
    return 0;
}
