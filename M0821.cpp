
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxm = 20+8;

_ n, m, c[maxn], cnt, a[maxn], x, d[maxn], nn, t[maxn], s, h[maxm];

_ search(_ x);
void add(_ x, _ a);
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        d[i] = a[i];
    }
    sort(d+1, d+1+n);
    nn = unique(d+1, d+1+n)-d-1;
    for(_ i = 1; i <= n; ++i) a[i] = lower_bound(d+1, d+1+nn, a[i])-d;
    for(_ i = 1; i <= m; ++i) scanf("%lld", &h[i]);
    sort(h+1, h+1+m, greater<_>());
    for(_ l = 1; l <= m; ++l) {
        x = h[l];
        for(_ i = 1; i <= x; ++i) {
            cnt = 0;
            for(_ j = i; j <= n; j += x) c[++cnt] = a[j];
            if(cnt <= 1) continue;
            for(_ j = cnt; j >= 1; --j) {
                s += search(c[j]-1);
                add(c[j], 1);
            }
            sort(c+1, c+1+cnt);
            for(_ j = i, k = 1; j <= n; j += x, ++k) {
                a[j] = c[k];
                add(c[k], -1);
            }
        }
    }
    
    printf("%lld\n", s);
    
    return 0;
}

void add(_ x, _ a) {
    for(; x <= n; x += x & -x) t[x] = t[x]+a;
    return;
}

_ search(_ x) {
    _ rv = 0;
    for(; x; x -= x & -x) rv += t[x];
    return rv;
}
