
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
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 249+8;

_ n, m, a[maxn], b[maxn], dp[maxn][maxn], s = -1E18, c[maxn];

void rotate2();
void rotate();
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= m; ++i) scanf("%lld", &b[i]);
    for(_ tt = 1; tt <= 3; ++tt) {
        for(_ t = 1; t <= m; ++t) {
            memset(dp, (1<<7)^(1<<6), sizeof dp);
            for(_ i = 0; i <= n+1; ++i) dp[i][0] = 0;
            for(_ i = 1; i <= n-1; ++i) for(_ j = m; j >= 1; --j) dp[i+1][j] = max(dp[i][j], dp[i-1][j-1]-(b[j]*(a[i]+a[i+1])));
            s = max(s, dp[n][m]);
            rotate();
        }
        rotate2();
    }
    printf("%lld\n", s);
    
    return 0;
}

void rotate() {
    _ sv = b[1];
    for(_ i = 1; i <= m-1; ++i) b[i] = b[i+1];
    b[m] = sv;
    return;
}

void rotate2() {
    _ sv = a[1];
    for(_ i = 1; i <= n; ++i) a[i] = a[i+1];
    a[n] = sv;
    return;
}
