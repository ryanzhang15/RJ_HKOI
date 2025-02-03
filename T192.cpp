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
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 4E5+8;
constant no = 289360691352306692;

_ n, m, lz[maxn<<2], a[maxn], x, y, z, c, o[maxn], cnt;
struct treeNode {
    _ l[3], r[3], v;
} t[maxn<<2];

inline _ read();
inline _ query(_ L, _ R, _ l, _ r, _ pos);
inline void update(_ L, _ R, _ c, _ l, _ r, _ pos);
inline void pushDown(_ pos, _ l, _ md, _ r);
inline void spn(_ pos, _ x);
inline void build(_ l, _ r, _ pos);
inline void pushUp(_ pos, _ lb, _ md, _ rb);
inline _ merge(_ l, _ r, _ lb, _ md, _ rb);
inline _ gc();
int main() {
    
    n = read();
    for(register _ i = 1; i <= n; ++i) a[i] = gc();
    build(1, n, 1);
    m = read();
    for(; m--; ) {
        c = read();
        x = read();
        y = read();
        if(c == 1) {
            z = gc();
            update(x, y, -z, 1, n, 1);
        } ef(c == 2) update(x, y, 1, 1, n, 1);
        else printf("%lld\n", query(x, y, 1, n, 1));
    }
    
    return 0;
}

inline _ gc() {
    char ch = getchar_unlocked();
    for(; ch != 'R' && ch != 'G' && ch != 'B'; ) ch = getchar_unlocked();
    return ch == 'R' ? 0 : (ch == 'G' ? 1 : 2);
}

inline _ merge(_ l, _ r, _ lb, _ md, _ rb) {
    _ rv = 0, mx = t[l].r[0], dx = 0, smx, sdx, tmx, tdx;
    if(t[l].r[1] > mx) {
        smx = mx;
        sdx = dx;
        mx = t[l].r[1];
        dx = 1;
    } else {
        smx = t[l].r[1];
        sdx = 1;
    }
    if(t[l].r[2] >= mx) {
        tmx = smx;
        tdx = sdx;
        smx = mx;
        sdx = dx;
        mx = t[l].r[2];
        dx = 2;
    } ef(t[l].r[2] > smx) {
        tmx = smx;
        tdx = sdx;
        smx = t[l].r[2];
        sdx = 2;
    } else {
        tmx = t[l].r[2];
        tdx = 2;
    }
    if(mx != md) return rv;
    if(~t[r].l[sdx] && ~t[r].l[tdx] && max(t[r].l[sdx], t[r].l[tdx]) <= rb) rv += (md-max(lb-1, smx))*(rb-max(t[r].l[sdx], t[r].l[tdx])+1);
    if(smx < lb) return rv;
    if(~t[r].l[tdx] && t[r].l[tdx] <= rb) rv += (smx-max(lb-1, tmx))*(rb-t[r].l[tdx]+1);
    if(tmx < lb) return rv;
    rv += (tmx-lb+1)*(rb-md);
    return rv;
}

inline void pushUp(_ pos, _ lb, _ md, _ rb) {
    t[pos].v = t[pos<<1].v+t[pos<<1|1].v+merge(pos<<1, pos<<1|1, lb, md, rb);
    for(_ i = 0; i < 3; ++i) {
        t[pos].l[i] = min(!~t[pos<<1].l[i] ? 1E11 : t[pos<<1].l[i], !~t[pos<<1|1].l[i] ? 1E11 : t[pos<<1|1].l[i]);
        if(t[pos].l[i] == 1E11) t[pos].l[i] = -1;
        t[pos].r[i] = max(t[pos<<1].r[i], t[pos<<1|1].r[i]);
    }
    return;
}

inline void build(_ l, _ r, _ pos) {
    lz[pos] = no;
    if(l == r) {
        for(_ i = 0; i < 3; ++i) t[pos].l[i] = t[pos].r[i] = -1;
        t[pos].l[a[r]] = t[pos].r[a[r]] = r;
        return;
    }
    _ md = (l+r)>>1;
    build(l, md, pos<<1);
    build(md+1, r, pos<<1|1);
    pushUp(pos, l, md, r);
    return;
}

inline void spn(_ pos, _ x) {
    if(x == 1) {
        _ c = t[pos].l[2];
        t[pos].l[2] = t[pos].l[1];
        t[pos].l[1] = t[pos].l[0];
        t[pos].l[0] = c;
        c = t[pos].r[2];
        t[pos].r[2] = t[pos].r[1];
        t[pos].r[1] = t[pos].r[0];
        t[pos].r[0] = c;
    } else {
        _ c = t[pos].l[2];
        t[pos].l[2] = t[pos].l[0];
        t[pos].l[0] = t[pos].l[1];
        t[pos].l[1] = c;
        c = t[pos].r[2];
        t[pos].r[2] = t[pos].r[0];
        t[pos].r[0] = t[pos].r[1];
        t[pos].r[1] = c;
    }
    return;
}

inline void pushDown(_ pos, _ l, _ md, _ r) {
    if(lz[pos] <= 0) {
        for(_ i = 0; i < 3; ++i) t[pos<<1].l[i] = t[pos<<1].r[i] = t[pos<<1|1].l[i] = t[pos<<1|1].r[i] = -1;
        _ c = lz[pos];
        t[pos<<1].l[-c] = l;
        t[pos<<1].r[-c] = md;
        t[pos<<1|1].l[-c] = md+1;
        t[pos<<1|1].r[-c] = r;
        t[pos<<1].v = t[pos<<1|1].v = 0;
        lz[pos<<1] = lz[pos<<1|1] = lz[pos];
    } else {
        spn(pos<<1, lz[pos]);
        spn(pos<<1|1, lz[pos]);
        if(lz[pos<<1] == no) lz[pos<<1] = lz[pos];
        ef(lz[pos<<1] <= 0) {
            _ cc = -lz[pos<<1];
            cc = (cc+lz[pos])%3;
            lz[pos<<1] = -cc;
        } else {
            lz[pos<<1] = (lz[pos<<1]+lz[pos])%3;
            if(!lz[pos<<1]) lz[pos<<1] = no;
        }
        if(lz[pos<<1|1] == no) lz[pos<<1|1] = lz[pos];
        ef(lz[pos<<1|1] <= 0) {
            _ cc = -lz[pos<<1|1];
            cc = (cc+lz[pos])%3;
            lz[pos<<1|1] = -cc;
        } else {
            lz[pos<<1|1] = (lz[pos<<1|1]+lz[pos])%3;
            if(!lz[pos<<1|1]) lz[pos<<1|1] = no;
        }
    }
    lz[pos] = no;
    return;
}

inline void update(_ L, _ R, _ c, _ l, _ r, _ pos) {
    if(L <= l && r <= R) {
        if(c <= 0) {
            for(_ i = 0; i < 3; ++i) t[pos].l[i] = t[pos].r[i] = -1;
            t[pos].l[-c] = l;
            t[pos].r[-c] = r;
            t[pos].v = 0;
            lz[pos] = c;
        } else {
            spn(pos, 1);
            if(lz[pos] == no) lz[pos] = 1;
            ef(lz[pos] <= 0) {
                _ cc = -lz[pos];
                cc = (cc+1)%3;
                lz[pos] = -cc;
            } ef(++lz[pos] == 3) lz[pos] = no;
        }
        return;
    }
    _ md = (l+r)>>1;
    if(lz[pos] != no) pushDown(pos, l, md, r);
    if(L <= md) update(L, R, c, l, md, pos<<1);
    if(R > md) update(L, R, c, md+1, r, pos<<1|1);
    pushUp(pos, l, md, r);
    return;
}

inline _ query(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) return t[pos].v;
    _ rv = 0, md = (l+r)>>1;
    if(lz[pos] != no) pushDown(pos, l, md, r);
    if(L <= md) rv += query(L, R, l, md, pos<<1);
    if(R > md) rv += query(L, R, md+1, r, pos<<1|1);
    if(L <= md && R > md) rv += merge(pos<<1, pos<<1|1, max(l, L), md, min(r, R));
    return rv;
}

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}
