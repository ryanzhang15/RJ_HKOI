
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

constant maxn = 5E2+8;

_ n, m, a[maxn], dp[maxn][maxn];
bitset<maxn> v[maxn];

_ recur(_ x, _ t);
int main() {
    
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    printf("%lld\n", recur(1, a[1]));
    
    return 0;
}

_ recur(_ x, _ t) {
    if(x > n) return 0;
    if(v[x][t-a[x]]) return dp[x][t-a[x]];
    _ c = 0, b = 1E18, i = x;
    for(; i <= n && a[i] <= t; ++i) c += a[i];
    b = min(b, t*(i-x)-c+recur(i, max(t+m, a[i])));
    for(; i <= n; ++i) {
        c += a[i];
        b = min(b, (i-x+1)*a[i]-c+recur(i+1, max(a[i+1], a[i]+m)));
    }
    v[x][t-a[x]] = true;
    return dp[x][t-a[x]] = b;
}
