#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E3+8;
constant mx = 1E4+8;

_ n, m, a[maxn][mx], b[maxn], x, y;
_D s = 1E9, c;
bool d;

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) {
        scanf("%lld%lld", &x, &y);
        a[i][y] = max(a[i][y], x);
    }
    for(_ i = 1; i <= 10000; ++i) {
        c = 0;
        d = true;
        for(_ j = 1; j <= n; ++j) {
            b[j] = max(b[j], a[j][i]);
            if(!a[j][i] && !b[j]) d = false;
            else c += b[j];
        }
        if(d) s = min(s, i/c);
    }
    printf("%Lf\n", s);
    
    return 0;
}
