#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef const long long constant;

constant maxn = 5E5+8;

_ n, t[maxn<<2], lt[maxn<<2], rt[maxn<<2], pr[maxn<<2], q, cmd, x, y;
bool in[maxn], lz[maxn<<2], lb[maxn<<2], rb[maxn<<2];
struct qr {
    _ t, lt, rt, pr, sz;
    bool lb, rb;
};

qr query(_ L, _ R, _ l, _ r, _ pos);
void update(_ L, _ R, _ l, _ r, _ pos);
void build(_ l, _ r, _ pos);
void pushUp(_ pos, _ ls, _ rs);
char gc();
int main() {

    //freopen("data.txt", "r", stdin);
    //freopen("main.txt", "w", stdout);

    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) in[i] = gc() == '1';
    build(1, n, 1);
    scanf("%lld", &q);
    for(; q--; ) {
        scanf("%lld%lld%lld", &cmd, &x, &y);
        if(cmd == 1) update(x, y, 1, n, 1);
        else printf("%lld\n", query(x, y, 1, n, 1).t);
    }

    return 0;
}

char gc() {
    char ch = getchar();
    for(; ch != '1' && ch != '0'; ) ch = getchar();
    return ch;
}

void pushUp(_ pos, _ ls, _ rs) {
    t[pos] = t[pos<<1]+t[pos<<1|1]+rt[pos<<1]*rs+lt[pos<<1|1]*ls;
    if(rb[pos<<1] == lb[pos<<1|1]) t[pos] -= ls*rs;
    pr[pos] = pr[pos<<1]+pr[pos<<1|1]-(rb[pos<<1]==lb[pos<<1|1]);
    rt[pos] = rt[pos<<1|1]+rt[pos<<1]+ls*(pr[pos<<1|1]-(rb[pos<<1]==lb[pos<<1|1]));
    lt[pos] = lt[pos<<1]+lt[pos<<1|1]+rs*(pr[pos<<1]-(rb[pos<<1]==lb[pos<<1|1]));
    lb[pos] = lb[pos<<1];
    rb[pos] = rb[pos<<1|1];
    return;
}

void pushDown(_ pos) {
    lz[pos<<1] = !lz[pos<<1];
    lz[pos<<1|1] = !lz[pos<<1|1];
    lb[pos<<1] = !lb[pos<<1];
    lb[pos<<1|1] = !lb[pos<<1|1];
    rb[pos<<1] = !rb[pos<<1];
    rb[pos<<1|1] = !rb[pos<<1|1];
    lz[pos] = false;
    return;
}

void build(_ l, _ r, _ pos) {
    if(l == r) {
        t[pos] = lt[pos] = rt[pos] = pr[pos] = 1;
        lb[pos] = rb[pos] = in[l];
        return;
    }
    _ md = (l+r)>>1;
    build(l, md, pos<<1);
    build(md+1, r, pos<<1|1);
    pushUp(pos, md-l+1, r-md);
    return;
}

void update(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) {
        lz[pos] = !lz[pos];
        lb[pos] = !lb[pos];
        rb[pos] = !rb[pos];
        return;
    }
    if(lz[pos]) pushDown(pos);
    _ md = (l+r)>>1;
    if(L <= md) update(L, R, l, md, pos<<1);
    if(R > md) update(L, R, md+1, r, pos<<1|1);
    pushUp(pos, md-l+1, r-md);
    return;
}

qr query(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) return (qr){t[pos], lt[pos], rt[pos], pr[pos], r-l+1, lb[pos], rb[pos]};
    if(lz[pos]) pushDown(pos);
    _ md = (l+r)>>1;
    if(L <= md && R > md) {
        qr x = query(L, R, l, md, pos<<1), y = query(L, R, md+1, r, pos<<1|1), rv;
        rv.t = x.t+y.t+x.rt*y.sz+y.lt*x.sz;
        if(x.rb == y.lb) rv.t -= x.sz*y.sz;
        rv.pr = x.pr+y.pr-(x.rb==y.lb);
        rv.rt = y.rt+x.rt+x.sz*(y.pr-(x.rb==y.lb));
        rv.lt = x.lt+y.lt+y.sz*(x.pr-(x.rb==y.lb));
        rv.lb = x.lb;
        rv.rb = y.rb;
        rv.sz = x.sz+y.sz;
        return rv;
    } ef(L <= md) return query(L, R, l, md, pos<<1);
    else return query(L, R, md+1, r, pos<<1|1);
}