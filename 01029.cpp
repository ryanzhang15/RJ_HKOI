
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 4E4+8;
_ n, r[3];

_ gcd(_ a, _ b);

struct frac {
    _ t, b;
    void times(_ x) {
        t*=x;
        _ g = gcd(t, b);
        t /= g;
        b /= g;
        return;
    }
    void minus(frac x) {
        _ d = x.b*b/gcd(x.b, b);
        x.t *= d/x.b;
        t *= d / b;
        t = x.t-t;
        b = d;
        _ g = gcd(t, b);
        t /= g;
        b /= g;
        return;
    }
    void outRec() {
        if(t == 1) printf("%lld\n", b);
        else printf("%lld / %lld\n", b, t);
        return;
    }
} a[maxn], c;

frac fracGcd(frac a, frac b);
bool cmp(frac a, frac b);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 0; i < n; ++i) {
        scanf("%lld", &a[i].b);
        a[i].t = 1;
    }
    sort(a, a+n, cmp);
    for(_ i = 0; i < n; ++i) a[i].times(2);
    for(_ i = 1; i < n; ++i) a[i].minus(a[0]);
    c = a[1];
    for(_ i = 2; i < n; ++i) c = fracGcd(c, a[i]);
    c.outRec();
    
    return 0;
}

_ gcd(_ a, _ b) {
    if(!b) return a;
    return gcd(b, a%b);
}

bool cmp(frac a, frac b) {
    return a.b < b.b;
}

frac fracGcd(frac a, frac b) {
    frac rv;
    rv.b = a.b*b.b/gcd(a.b, b.b);
    a.t *= rv.b/a.b;
    b.t *= rv.b/b.b;
    rv.t = gcd(a.t, b.t);
    _ g = gcd(rv.t, rv.b);
    rv.t /= g;
    rv.b /= g;
    return rv;
}
