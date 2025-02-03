#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, c, a[maxn], fm, sm, pr[maxn], dv;

_ binSearch(_ bd, _ c, _ fp, _ sp);
bool canKill(_ fp, _ sp);
_ rangeMax();
int main() {
    
    scanf("%lld%lld", &n, &c);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    fm = rangeMax();
    a[fm] = -a[fm];
    sm = rangeMax();
    a[fm] = -a[fm];
    for(_ i = 1; i <= n; ++i) pr[i] = a[i] + pr[i-1];
    
    //will 0 ghosts work?
    if(canKill(-1, -1)) {
        puts("0");
        exit(0);
    }
    //will 1 ghost work?
    for(_ i = 2; i <= n; ++i) if(canKill(i, -1)) {
        puts("1");
        printf("%lld\n", i);
        exit(0);
    }
    //will 2 ghosts work?
    for(_ i = 2; i <= n; ++i) if(canKill(i, i == fm ? sm : fm)) {
        puts("2");
        printf("%lld\n", i);
        for(_ j = 1; j <= n; ++j) if(i != j && canKill(i, j)) {
            printf("%lld\n", j);
            break;
        }
        exit(0);
    }
    //pacman must be strong
    puts("Pac-man is strong!");
    
    return 0;
}

_ rangeMax() {
    _ rv = -1, ri;
    for(_ i = 1; i <= n; ++i) if(a[i] > rv) {
        rv = a[i];
        ri = i;
    }
    return ri;
}

bool canKill(_ fp, _ sp) {
    _ mns = a[1], t = c;
    if(~fp) mns = a[fp];
    if(~sp) mns = a[sp];
    if(t <= mns) return true;
    t -= mns;
    _ p = ~fp ? 1 : 2;
    if(~sp) {
        if(t <= a[fp]) return true;
        t += a[fp];
    }
    for(; p == fp || p == sp; ) ++p;
    for(; t <= 1E7 && p <= n; ) {
        p = binSearch(p, t, fp, sp);
        if(!~p) return true;
        _ nxt = p+1;
        for(; nxt == fp || nxt == sp; ) ++nxt;
        if(nxt > n) break;
        t += dv;
        if(t <= a[nxt]) return true;
        t += a[nxt];
        p = nxt+1;
        for(; p == fp || p == sp; ) ++p;
    }
    return false;
}

_ binSearch(_ bd, _ c, _ fp, _ sp) {
    _ rv = -1, l = bd, r = n, md;
    for(; l == fp || l == sp; ) ++l;
    for(; r == fp || r == sp; ) --r;
    for(; l <= r; ) {
        md = (l+r)>>1;
        for(; md == fp || md == sp; ) --md;
        _ cv = pr[md]-pr[bd-1];
        if(~fp && md > fp && bd < fp) cv -= a[fp];
        if(~sp && md > sp && bd < sp) cv -= a[sp];
        if(cv < c) {
            rv = md;
            l = md+1;
            dv = cv;
            for(; l == fp || l == sp; ) ++l;
        } else {
            r = md-1;
            for(; r == fp || r == sp; ) --r;
        }
    }
    return rv;
}

