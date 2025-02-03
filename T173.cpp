#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef string str;
typedef long double _D;
typedef const long long constant;

constant maxn = 5E5+8;
constant maxp = 4E4+8;
struct line {
    _D m, b;
} a[maxp];
struct pt {
    _ x, y, u, v;
} b[maxp];
_ u[maxn], d[maxn], l[maxn], r[maxn], n, m, q, c1, c2;
struct lichao {
    _ t[maxn<<2];
    _ vl(_ ln, _ x) {
        return a[ln].m*x+a[ln].b;
    }
    void clr() {
        memset(t, 0, sizeof t);
        return;
    }
    void update(_ l, _ r, _ c, _ pos) {
        _ md = (l+r)>>1;
        if(vl(c, md) > vl(t[pos], md)) swap(t[pos], c);
        if(l == r) return;
        if(vl(c, l) > vl(t[pos], l)) update(l, md, c, pos<<1);
        ef(vl(c, r) > vl(t[pos], r)) update(md+1, r, c, pos<<1|1);
    }
    _ query(_ l, _ r, _ k, _ pos) {
        _ md = (l+r)>>1, rv = vl(t[pos], k);
        if(l == r) return rv;
        if(k <= md) return max(rv, query(l, md, k, pos<<1));
        else return max(rv, query(md+1, r, k, pos<<1|1));
    }
    void build() {
        for(_ i = 1; i <= n; ++i) update(1, m, i, 1);
        return;
    }
} t;

_p meeting();
int main() {

#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    a[0].m = a[0].b = -1E11;

    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%lld%lld%lld%lld", &b[i].x, &b[i].y, &b[i].u, &b[i].v);
    for(_ i = 1; i <= n; ++i) {
        a[i].m = b[i].v;
        a[i].b = b[i].y;
    }
    t.build();
    for(_ i = 1; i <= m; ++i) u[i] = t.query(1, m, i, 1);
    t.clr();
    for(_ i = 1; i <= n; ++i) {
        a[i].m = -b[i].v;
        a[i].b = -b[i].y;
    }
    t.build();
    for(_ i = 1; i <= m; ++i) d[i] = -t.query(1, m, i, 1);
    t.clr();
    for(_ i = 1; i <= n; ++i) {
        a[i].m = b[i].u;
        a[i].b = b[i].x;
    }
    t.build();
    for(_ i = 1; i <= m; ++i) r[i] = t.query(1, m, i, 1);
    t.clr();
    for(_ i = 1; i <= n; ++i) {
        a[i].m = -b[i].u;
        a[i].b = -b[i].x;
    }
    t.build();
    for(_ i = 1; i <= m; ++i) l[i] = -t.query(1, m, i, 1);
    scanf("%lld", &q);
    for(; q--; ) {
        scanf("%lld%lld", &c1, &c2);
        _p cr = meeting();
        printf("%lld %lld\n", cr.first, cr.second);
    }

    return 0;
}

_ scr(_ x) {
    if(!x) return -1E17;
    return max(((r[x]-l[x])>>1)*c1, ((u[x]-d[x])>>1)*c2);
}

_p meeting() {
    _ lt = 0, rt = m, md;
    for(; rt-lt > 1; ) {
        md = (lt+rt)>>1;
        if(scr(md) > scr(md+1)) lt = md;
        else rt = md;
    }
    return make_pair(rt, scr(rt));
}