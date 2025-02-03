
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

constant maxn = 20+8;
constant maxexp = (1<<20)+8;

_ n, m, q, dp[maxn][maxexp];

_ in();
int main() {
    
    scanf("%lld%lld%lld", &n, &m, &q);
    for(; m--; ) ++dp[0][in()];
    for(_ i = 0; i <= n; ++i) for(_ j = 0; j <= (1<<n)-1; ++j) {
        dp[i+1][j] = dp[i][j];
        if(!(j & (1<<i))) dp[i+1][j] += dp[i][j|(1<<i)];
    }
    for(; q--; ) printf("%lld\n", dp[n][in()]);
    
    return 0;
}

_ in() {
    _ rv = 0;
    char ch = getchar_unlocked();
    for(; ch != '0' && ch != '1'; ) ch = getchar_unlocked();
    for(; ch == '0' || ch == '1'; ch = getchar_unlocked()) rv = (rv<<1) | (ch == '1');
    return rv;
}
