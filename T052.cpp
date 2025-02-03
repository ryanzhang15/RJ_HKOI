
#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <numeric>

#define ef else if

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E3+8;
_ n, cnt, f[maxn], s;
struct node {
    _ x;
    char s[10];
    void in(_ p) {
        x = p;
        scanf("%s", s);
        return;
    }
} a[maxn];
struct edge {
    _ l, a, b;
    bool operator < (const edge &b) const {
        return l < b.l;
    }
} e[maxn*maxn];

_ find(_ x);
_ hamming(char *a, char *b);
int main() {
    
    scanf("%lld", &n);
    s = 7+n-1;
    for(_ i = 1; i <= n; ++i) a[i].in(i);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(i != j) e[++cnt] = (edge){hamming(a[i].s, a[j].s), i, j};
    sort(e+1, e+1+cnt);
    for(_ i = 1; i <= n; ++i) f[i] = i;
    for(_ i = 1; i <= cnt; ++i) {
        _ o = find(e[i].a), t = find(e[i].b);
        if(o != t) {
            s += e[i].l;
            f[o] = t;
        }
    }
    
    printf("%lld\n", s);
    
    return 0;
}

_ hamming(char *a, char *b) {
    _ rv = 0;
    for(_ i = 0; i < 7; ++i) rv += a[i] != b[i];
    return rv;
}

_ find(_ x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
