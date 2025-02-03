
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

constant maxn = 5E4+8;
constant maxb = 50+8;

_ n, t, l[maxb], m[maxb], b[maxb][maxb], dp[maxn];

int main() {

    scanf("%lld%lld", &n, &t);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld%lld", &l[i], &m[i]);
        for(_ j = 1; j <= m[i]; ++j) scanf("%lld", &b[i][j]);
        sort(b[i]+1, b[i]+1+m[i]);
    }
    
    for(_ i = 1; i <= n; ++i) for(_ j = t; j-1; --j) {
        _ pre = l[i];
        for(_ k = 1; k <= m[i]; ++k) {
            pre += b[i][k];
            if(!((j-pre) & (1LL<<63))) dp[j] = max(dp[j], dp[j-pre]+k);
        }
    }
    
    printf("%lld\n", dp[t]);

    return 0;
}


