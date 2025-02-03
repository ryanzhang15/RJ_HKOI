#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef string str;
typedef long double _D;
typedef const long long constant;

struct coords {
    _ x, y;
} t1, t2, t3;
_ n, lt, rt, up, dn, l, r, md, x, y;

void answer(coords a, coords b, coords c);
bool qrrect(coords a, coords b, coords c, coords d);
bool qr(coords a, coords b, coords c);
int main() {

    scanf("%lld", &n);
#ifndef ONLINE_JUDGE
    scanf("%lld%lld%lld%lld%lld%lld", &t1.x, &t1.y, &t2.x, &t2.y, &t3.x, &t3.y);
#endif

    l = -n+1;
    r = n;
    lt = -n;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(!qrrect((coords){-n, -n}, (coords){md, -n}, (coords){md, n}, (coords){-n, n})) {
            lt = md;
            l = md+1;
        } else r = md-1;
    }
    l = -n;
    r = n-1;
    rt = n;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(!qrrect((coords){md, -n}, (coords){n, -n}, (coords){n, n}, (coords){md, n})) {
            rt = md;
            r = md-1;
        } else l = md+1;
    }
    l = -n+1;
    r = n;
    up = -n;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(!qrrect((coords){-n, -n}, (coords){n, -n}, (coords){n, md}, (coords){-n, md})) {
            up = md;
            l = md+1;
        } else r = md-1;
    }
    l = -n;
    r = n-1;
    dn = n;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(!qrrect((coords){-n, md}, (coords){n, md}, (coords){n, n}, (coords){-n, n})) {
            dn = md;
            r = md-1;
        } else l = md+1;
    }
    if(qr((coords){lt, up}, (coords){lt+1, up}, (coords){lt, up+1})) {
        x = up;
        l = up+1;
        r = dn;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){lt, up}, (coords){rt, up}, (coords){rt, md})) {
                x = md;
                l = md+1;
            } else r = md-1;
        }
        y = lt;
        l = lt+1;
        r = rt;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){lt, up}, (coords){lt, dn}, (coords){md, dn})) {
                y = md;
                l = md+1;
            } else r = md-1;
        }
        answer((coords){lt, up}, (coords){rt, x}, (coords){y, dn});
    } ef(qr((coords){rt, up}, (coords){rt-1, up}, (coords){rt, up+1})) {
        x = up;
        l = up+1;
        r = dn;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){rt, up}, (coords){lt, up}, (coords){lt, md})) {
                x = md;
                l = md+1;
            } else r = md-1;
        }
        y = rt;
        l = lt;
        r = rt-1;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){rt, up}, (coords){rt, dn}, (coords){md, dn})) {
                y = md;
                r = md-1;
            } else l = md+1;
        }
        answer((coords){rt, up}, (coords){lt, x}, (coords){y, dn});
    } ef(qr((coords){rt, dn}, (coords){rt-1, dn}, (coords){rt, dn-1})) {
        x = dn;
        l = up;
        r = dn-1;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){rt, dn}, (coords){lt, dn}, (coords){lt, md})) {
                x = md;
                r = md-1;
            } else l = md+1;
        }
        y = rt;
        l = lt;
        r = rt-1;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){rt, dn}, (coords){rt, up}, (coords){md, up})) {
                y = md;
                r = md-1;
            } else l = md+1;
        }
        answer((coords){rt, dn}, (coords){lt, x}, (coords){y, up});
    } else {
        x = dn;
        l = up;
        r = dn-1;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){rt, dn}, (coords){lt, dn}, (coords){rt, md})) {
                x = md;
                r = md-1;
            } else l = md+1;

        }
        y = lt;
        l = lt+1;
        r = rt;
        for(; l <= r; ) {
            md = (l+r)>>1;
            if(!qr((coords){lt, dn}, (coords){lt, up}, (coords){md, up})) {
                y = md;
                l = md+1;
            } else r = md-1;
        }
        answer((coords){lt, dn}, (coords){rt, x}, (coords){y, up});
    }

    return 0;
}

bool qr(coords a, coords b, coords c) {
    printf("Q %lld %lld %lld %lld %lld %lld\n", a.x, a.y, b.x, b.y, c.x, c.y);
    fflush(stdout);
    _ rv;
    scanf("%lld", &rv);
    return !!rv;
}

bool qrrect(coords a, coords b, coords c, coords d) {
    return rand() & 1 ? (qr(a, b, c) || qr(a, d, c)) : (qr(a, d, c) || qr(a, b, c));
}

void answer(coords a, coords b, coords c) {
    printf("A %lld\n", abs((a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y)));
    fflush(stdout);
    exit(0);
}
