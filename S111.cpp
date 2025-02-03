
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E2+8;

_ n, m, dir, x, y, z, a[maxn], s, c;

int main() {
    
    scanf("%lld%lld%lld", &n, &m, &dir);
    for(; m--; ) {
        scanf("%lld%lld%lld", &x, &y, &z);
        a[x+101-dir*y] += z;
        s += z;
    }
    for(_ i = -100*dir; i <= 100; ++i) {
        c += a[i+100]<<1;
        if(s-a[i+101] == c) {
            printf("%lld\n", i);
            exit(0);
        }
    }
    puts("OH NO");
    
    return 0;
}
