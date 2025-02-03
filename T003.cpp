
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

constant maxn = 1E2+8;

_ n, l, c, dp[maxn][maxn], p[maxn], x, sp;

int main() {
    
    memset(dp, 4, sizeof dp);
    scanf("%lld%lld%lld", &n, &l, &c);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &x);
        p[i] = p[i-1]+x;
    }
    dp[0][0] = 0;
    for(_ i = 1; ; ++i) {
        for(_ j = 1; j <= n; ++j) for(_ k = 0; k <= j-1; ++k) {
            if(p[j]-p[k] > l) continue;
            ef(!(l-(p[j]-p[k]))) sp = 0;
            ef(l-(p[j]-p[k]) <= 10) sp = -c;
            else sp = (l-(p[j]-p[k])-10)*(l-(p[j]-p[k])-10);
            dp[i][j] = min(dp[i][j], dp[i-1][k]+sp);
        }
        if(dp[i][n] < 1E12) {
            printf("%lld %lld\n", i, dp[i][n]);
            exit(0);
        }
    }
    
    return 0;
}


