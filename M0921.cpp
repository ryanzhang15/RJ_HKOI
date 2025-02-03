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

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef int _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = (_)(1E6+8) << 2;
//constant maxn = (_)5<<2;

_ t[maxn], z[maxn], a[maxn], n, m, x, k;

_ query(_ L, _ R, _ l, _ r, _ pos);
void pushDown(_ pos, _ ls, _ rs);
void update(_ L, _ R, _ c, _ l, _ r, _ pos);
void build(_ l, _ r, _ pos);
void pushUp(_ pos);

int main(int argc, char * argv[]) {
    
    scanf("%d%d", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%d", &a[i]);
    build(1, n, 1);
    for(; m--; ) {
        scanf("%d%d", &x, &k);
        printf("%d\n", query(x, k, 1, n, 1));
    }
    
    return 0;
}

void pushUp(_ pos) {
    t[pos] = max(t[pos<<1], t[pos<<1|1]);
}

void build(_ l, _ r, _ pos) {
    if(l == r) {
        t[pos] = a[r];
        return;
    }
    _ m = (l+r)>>1;
    build(l, m, pos<<1);
    build(m+1, r, pos<<1|1);
    pushUp(pos);
}

void update(_ L, _ R, _ c, _ l, _ r, _ pos) {
    if(L <= l && r <= R) {
        t[pos] += c * (r-l+1);
        z[pos] += c;
        return;
    }
    _ m = (l+r)>>1;
    if(z[pos]) pushDown(pos, m-l+1, r-m);
    if(L <= m) update(L, R, c, l, m, pos<<1);
    if(R > m) update(L, R, c, m+1, r, pos<<1|1);
    pushUp(pos);
}

void pushDown(_ pos, _ ls, _ rs) {
    z[pos<<1] += z[pos];
    z[pos<<1|1] += z[pos];
    t[pos<<1] += z[pos]*ls;
    t[pos<<1|1] += z[pos]*rs;
    z[pos] = 0;
}

_ query(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) return t[pos];
    _ s = -1E12, m = (l+r)>>1;
    pushDown(pos, m-l+1, r-m);
    if(L <= m) s = max(s, query(L, R, l, m, pos<<1));
    if(R > m) s = max(s, query(L, R, m+1, r, pos<<1|1));
    return s;
}
