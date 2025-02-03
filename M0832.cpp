
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

_ n, m, k, a[maxn][maxn], s;

void twoPtr(_ sx, _ sy);
_ getA(_ x1, _ y1, _ x2, _ y2);
int main() {
    
    scanf("%lld%lld%lld", &n, &m, &k);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
    for(_ i = 1; i <= n; ++i) for(_ j = 2; j <= m; ++j) a[i][j] += a[i][j-1];
    for(_ i = 2; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] += a[i-1][j];
    for(_ i = n; i > 1; --i) twoPtr(i, 1);
    for(_ i = 1; i <= m; ++i) twoPtr(1, i);
    printf("%lld\n", s);
    
    return 0;
}

_ getA(_ x1, _ y1, _ x2, _ y2) {
    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}

void twoPtr(_ sx, _ sy) {
    _ p1x = sx, p1y = sy, p2x = sx, p2y = sy;
    for(; p1x <= n && p2x <= n && p1y <= m && p2y <= m; ) if(getA(p1x, p1y, p2x, p2y) > k) {
        if(p1x == p2x && p1y == p2y) {
            ++p2x;
            ++p2y;
        }
        ++p1x;
        ++p1y;
    } else {
        s = max(s, p2x-p1x+1);
        ++p2x;
        ++p2y;
    }
    return;
}
