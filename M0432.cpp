#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;
constant maxm = 1E5+8;

_ n, l, m, p[maxn], t[maxn], x, y, mx;

int main() {
    
    scanf("%lld%lld%lld", &n, &l, &m);
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld%lld", &x, &y);
        t[x] = t[x+1] = max(t[x]+y-p[x], t[x+1]+y-p[x+1])+1;
        p[x] = p[x+1] = y;
    }
    for(_ i = 1; i <= n; ++i) mx = max(mx, t[i]+l-p[i]);
    printf("%lld\n", mx);
    
    return 0;
}
