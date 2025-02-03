
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

constant maxn = 10+8;
constant maxm = 1E2+8;

_ a[maxn][maxm], dp[maxn][maxm], f[maxn][maxm], n, m, b, t;

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
    for(_ i = 1; i <= n; ++i) dp[i][m] = a[i][m];
    for(_ i = m-1; i >= 1; --i) for(_ j = 1; j <= n; ++j) {
        b = 1E18;
        for(_ k = -1; k <= 1; ++k) {
            t = (j+k-1+n)%n+1;
            if(b > dp[t][i+1] || (b == dp[t][i+1] && t < f[j][i])) {
                b = dp[t][i+1];
                f[j][i] = t;
            }
        }
        dp[j][i] = a[j][i] + b;
    }
    b = 1E18;
    for(_ i = 1; i <= n; ++i) if(dp[i][1] < b) {
        b = dp[i][1];
        t = i;
    }
    for(_ i = 1; i <= m; ++i) {
        printf("%lld ", t);
        t = f[t][i];
    }
    putchar(10);
    printf("%lld\n", b);
    return 0;
}

