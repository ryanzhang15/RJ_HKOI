
#include<bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+88;
_ n, q, a[maxn], x, y;
struct value {
    _ bgs, cl, cr, sum;
} t[maxn<<2];

_ query();
void update(_ p, _ c, _ l, _ r, _ pos);
void build(_ l, _ r, _ pos);
void newNum(_ pos, _ num);
void pushUp(_ pos);
int main() {
    
    scanf("%lld%lld", &n, &q);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    build(1, n, 1);
    printf("%lld\n", query());
    for(; q--; ) {
        scanf("%lld%lld", &x, &y);
        update(x, y, 1, n, 1);
        printf("%lld\n", query());
    }
    
    return 0;
}

void pushUp(_ pos) {
    t[pos].bgs = max(max(t[pos<<1].bgs, t[pos<<1|1].bgs), t[pos<<1].cr + t[pos<<1|1].cl);
    t[pos].sum = t[pos<<1].sum + t[pos<<1|1].sum;
    t[pos].cl = max(t[pos<<1].cl, t[pos<<1].sum+t[pos<<1|1].cl);
    t[pos].cr = max(t[pos<<1|1].cr, t[pos<<1|1].sum+t[pos<<1].cr);
    return;
}

void newNum(_ pos, _ num) {
    t[pos].sum = num;
    t[pos].bgs = max((_)0, num);
    t[pos].cl = max((_)0, num);
    t[pos].cr = max((_)0, num);
    return;
}

void build(_ l, _ r, _ pos) {
    if(l == r) {
        newNum(pos, a[l]);
        return;
    }
    _ m = (l+r)>>1;
    build(l, m, pos<<1);
    build(m+1, r, pos<<1|1);
    pushUp(pos);
    return;
}

void update(_ p, _ c, _ l, _ r, _ pos) {
    if(l == p && r == p) {
        newNum(pos, c);
        return;
    }
    _ m = (l+r)>>1;
    if(p <= m) update(p, c, l, m, pos<<1);
    else update(p, c, m+1, r, pos<<1|1);
    pushUp(pos);
    return;
}

_ query() {
    return t[1].bgs;
}
