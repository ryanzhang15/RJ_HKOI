#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E4;

_ w, h, n, x, y, a[maxn+8], s, i;

_ gen(_ x, _ y);
bool bin(_ x);
int main() {
    
    scanf("%lld%lld%lld", &w, &h, &n);
    for(i = 1; i <= n; ++i) {
        scanf("%lld%lld", &x, &y);
        a[i] = gen(x, y);
        s += (bin(gen(x-4, y)) && bin(gen(x-3, y)) && bin(gen(x-2, y+3)) && bin(gen(x-2, y+2)) && bin(gen(x-1, y))) + (bin(gen(x-4, y)) && bin(gen(x-3, y)) && bin(gen(x-2, y-3)) && bin(gen(x-2, y-2)) && bin(gen(x-1, y))) + (bin(gen(x-3, y-2)) && bin(gen(x-2, y-2)) && bin(gen(x, y-4)) && bin(gen(x, y-3)) && bin(gen(x, y-1))) + (bin(gen(x-3, y-2)) && bin(gen(x-3, y-1)) && bin(gen(x-3, y+1)) && bin(gen(x-3, y+2)) && bin(gen(x-1, y)));
    }
    
    printf("%lld\n", s);
    
    return 0;
}

_ gen(_ x, _ y) {
    return x*maxn+y;
}

bool bin(_ x) {
    _ l = 1, r = i, md;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(a[md] == x) return true;
        ef(a[md] > x) r = md-1;
        else l = md+1;
    }
    return false;
}
