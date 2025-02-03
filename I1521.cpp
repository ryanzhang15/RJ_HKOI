
#ifdef __cplusplus
extern "C" {
#endif
int init(int N, int X[], int Y[]);
int updateX(int pos, int val);
int updateY(int pos, int val);
#ifdef __cplusplus
}
#endif

#include <set>
#include <cstdio>
#include <cstdlib>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E5+8;
constant mod = 1E9+7;

_ t1[maxn<<2], t2[maxn<<2], a[maxn], b[maxn], n;
set<_, greater<_> > st;

void pushUp1(_ pos) {
    t1[pos] = max(t1[pos<<1], t1[pos<<1|1]);
    return;
}

void build1(_ l, _ r, _ pos) {
    if(l == r) {
        t1[pos] = b[r];
        return;
    }
    _ md = (l+r)>>1;
    build1(l, md, pos<<1);
    build1(md+1, r, pos<<1|1);
    pushUp1(pos);
    return;
}

void update1(_ p, _ c, _ l, _ r, _ pos) {
    if(l == r) {
        t1[pos] = c;
        return;
    }
    _ md = (l+r)>>1;
    if(p <= md) update1(p, c, l, md, pos<<1);
    else update1(p, c, md+1, r, pos<<1|1);
    pushUp1(pos);
    return;
}

_ query1(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) return t1[pos];
    _ rv = -1E11, md = (l+r)>>1;
    if(L <= md) rv = max(rv, query1(L, R, l, md, pos<<1));
    if(R > md) rv = max(rv, query1(L, R, md+1, r, pos<<1|1));
    return rv;
}

void pushUp2(_ pos) {
    t2[pos] = (t2[pos<<1]*t2[pos<<1|1])%mod;
    return;
}

void build2(_ l, _ r, _ pos) {
    if(l == r) {
        t2[pos] = a[r];
        return;
    }
    _ md = (l+r)>>1;
    build2(l, md, pos<<1);
    build2(md+1, r, pos<<1|1);
    pushUp2(pos);
}

void update2(_ p, _ c, _ l, _ r, _ pos) {
    if(l == r) {
        t2[pos] = c;
        return;
    }
    _ md = (l+r)>>1;
    if(p <= md) update2(p, c, l, md, pos<<1);
    else update2(p, c, md+1, r, pos<<1|1);
    pushUp2(pos);
    return;
}

_ query2(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) return t2[pos];
    _ rv = 1, md = (l+r)>>1;
    if(L <= md) rv = (rv*query2(L, R, l, md, pos<<1))%mod;
    if(R > md) rv = (rv*query2(L, R, md+1, r, pos<<1|1))%mod;
    return rv;
}

int getMx() {
    if(st.size() == 1) return (int)(query1(1, n, 1, n, 1)%mod);
    __int128 ct = 1, mx = -1E11, dx = -1, by = -1;
    set<_, greater<_> >::iterator x = st.begin(), y = st.begin();
    ++y;
    for(;;) {
        if(y == st.end()) break;
        ct *= a[*y];
        if(ct > mod*mod+100) break;
        ++x;
        ++y;
    }
    y = x;
    --y;
    ct = 1;
    for(;;) {
        ct *= a[*x];
        __int128 cy = query1(*x, (*y)-1, 1, n, 1);
        __int128 cr = ct*cy;
        if(cr > mx) {
            mx = cr;
            dx = *x;
            by = cy;
        }
        if(y == st.begin()) break;
        --x;
        --y;
    }
    _ qr = query1(1, n, 1, n, 1);
    if(qr > mx) return (int)(qr%mod);
    return (int)(query2(1, dx, 1, n, 1)%mod*by%mod);
}

int init(int N, int X[], int Y[]) {
    n = N;
    for(_ i = 1; i <= n; ++i) {
        a[i] = X[i-1];
        if(a[i] != 1) st.insert(i);
        b[i] = Y[i-1];
    }
    build1(1, n, 1);
    build2(1, n, 1);
    st.insert(n+1);
    return getMx();
}

int updateX(int pos, int val) {
    ++pos;
    if(val != 1) st.insert(pos);
    else st.erase(pos);
    a[pos] = val;
    update2(pos, val, 1, n, 1);
    return getMx();
}

int updateY(int pos, int val) {
    ++pos;
    update1(pos, val, 1, n, 1);
    return getMx();
}

//int nn, aa[maxn], bb[maxn];
//_ cg, mm, pp, vv;
//
//int main() {
//    freopen("/Users/ryanzhang/Downloads/ioi2015tests/horses/tests/27", "r", stdin);
//    scanf("%d", &nn);
//    for(_ i = 1; i <= nn; ++i) scanf("%d", &aa[i-1]);
//    for(_ i = 1; i <= nn; ++i) scanf("%d", &bb[i-1]);
//    printf("%d\n", init(nn, aa, bb));
//    scanf("%lld", &mm);
//    for(; mm--; ) {
//        scanf("%lld%lld%lld", &cg, &pp, &vv);
//        if(cg == 1) printf("%d\n", updateX(pp, vv));
//        else printf("%d\n", updateY(pp, vv));
//    }
//
//    return 0;
//}
