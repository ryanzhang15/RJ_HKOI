#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, m, c, k, p;
unsigned long long s = 1, x, y;
bitset<65> b, nb;

int main() {
    
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
    
    nb.flip();
    scanf("%lld%lld%lld%lld", &n, &m, &c, &k);
    for(_ i = 1; i <= n; ++i) {
        scanf("%llu", &x);
        b |= x;
    }
    for(_ i = 1; i <= m; ++i) {
        scanf("%llu%llu", &x, &y);
        nb[x] = false;
    }
    b |= nb;
    
    for(_ i = 0; i < k; ++i) if(b[i]) ++p;
    if(p == 64 && !n) puts("18446744073709551616");
    else {
        if(p == 64) printf("%llu\n", (s<<63)-n+(s<<63));
        else printf("%llu\n", (s<<p)-n);
    }
    
    return 0;
}

/*
 4 10 10 3
 4 5 0 1
 1 4
 1 6
 0 8
 1 3
 1 10
 0 9
 1 7
 0 5
 3 1
 3 2
 */
