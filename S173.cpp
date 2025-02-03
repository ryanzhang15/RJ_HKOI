
/*
 template by c8kbf
 */

// macOS doesn't have <bits/stdc++.h> (shame)
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

constant mod1 = 91782333LL;
constant mod2 = 91059438LL;
constant maxn = 2E5+8;

_ n, m, l, r, md, s = -1, x, y, a[maxn], b[maxn], c[maxn][2];
unordered_set<_> s1, s2;
vector<_> g[maxn];

inline _ fast(_ x, _ md);
inline bool check();
int main() {
    
    scanf("%lld%lld", &n, &m);
    r = m;
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld", &x);
        for(; x--; ) {
            scanf("%lld", &y);
            g[i].push_back(y);
        }
    }
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(check()) {
            s = md;
            r = md-1;
        } else l = md+1;
    }
    if(!~s) puts("Impossible");
    else printf("%lld\n", s);
    
    return 0;
}

inline _ fast(_ x, _ md) {
    if(c[x][md==mod1]) return c[x][md==mod1];
    if(!x) return 1;
    _ c = fast(x>>1, md);
    c = (c*c)%md;
    if(x & 1) c = (c<<1)%md;
    return ::c[x][md==mod1] = c;
}

inline bool check() {
    s1.clear();
    s2.clear();
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for(_ i = 1; i <= md; ++i) for(_ j : g[i]) {
        a[j] = (a[j]+fast(i, mod1))%mod1;
        b[j] = (b[j]+fast(i, mod2))%mod2;
    }
    for(_ i = 1; i <= n; ++i) {
        if(s1.count(a[i]) && s2.count(b[i])) return false;
        s1.insert(a[i]);
        s2.insert(b[i]);
    }
    return true;
}
