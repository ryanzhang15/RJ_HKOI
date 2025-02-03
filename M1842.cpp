
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;
constant lg = maxn*30;
_ n, q, x, y, z, nn, a[maxn], b[maxn], r[maxn], t[lg], le[lg], ri[lg], cnt;

_ query(_ u, _ v, _ l, _ r, _ k);
_ update(_ pre, _ l, _ r, _ x);
_ build(_ l, _ r);
int main() {
    
    scanf("%lld%lld", &n, &q);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    sort(b+1, b+1+n);
    nn = unique(b+1, b+1+n)-b-1;
    t[0] = build(1, nn);
    for(_ i = 1; i <= n; ++i) r[i] = update(r[i-1], 1, nn, lower_bound(b+1, b+1+nn, a[i])-b);
    for(; q--; ) {
        scanf("%lld%lld", &x, &y);
        z = (y-x+2)>>1;
        printf("%lld\n", b[query(r[x-1], r[y], 1, nn, z)]);
    }
    
    return 0;
}

_ build(_ l, _ r) {
    _ rt = ++cnt;
    if(l < r) {
        _ md = (l+r)>>1;
        le[rt] = build(l, md);
        ri[rt] = build(md+1, r);
    }
    return rt;
}

_ update(_ pre, _ l, _ r, _ x) {
    _ rt = ++cnt;
    le[rt] = le[pre];
    ri[rt] = ri[pre];
    t[rt] = t[pre]+1;
    if(l < r) {
        _ md = (l+r)>>1;
        if(x <= md) le[rt] = update(le[pre], l, md, x);
        else ri[rt] = update(ri[pre], md+1, r, x);
    }
    return rt;
}

_ query(_ u, _ v, _ l, _ r, _ k) {
    if(l >= r) return l;
    _ x = t[le[v]]-t[le[u]], md = (l+r)>>1;
    if(x >= k) return query(le[u], le[v], l, md, k);
    else return query(ri[u], ri[v], md+1, r, k-x);
}
