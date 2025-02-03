
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

constant mod = 1E8-3;
constant maxn = 1E5+8;

_ n, a[maxn], b[maxn], c[maxn], d[maxn], e[maxn], t[maxn], s;

bool cmp2(_ x, _ y);
bool cmp1(_ x, _ y);
_ search(_ x);
void add(_ x);
int main() {
    
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        c[i] = i;
    }
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &b[i]);
        d[i] = i;
    }
    sort(c+1, c+1+n, cmp1);
    sort(d+1, d+1+n, cmp2);

    for(_ i = 1; i <= n; ++i) e[c[i]] = d[i];

    for(_ i = n; i >= 1; --i) {
        s = (s+search(e[i]))%mod;
        add(e[i]);
    }

    printf("%lld\n", s);

    return 0;
}

void add(_ x) {
    for(; x <= n; x += x & -x) t[x] = (t[x]+1)%mod;
    return;
}

_ search(_ x) {
    _ rv = 0;
    for(; x; x -= x & -x) rv = (rv+t[x])%mod;
    return rv;
}

bool cmp1(_ x, _ y) {
    return a[x] < a[y];
}

bool cmp2(_ x, _ y) {
    return b[x] < b[y];
}
