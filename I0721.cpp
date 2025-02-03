
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

typedef int _;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef double _D;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxm = 4;

_ n, a[maxn], dp[2][maxm][maxm][maxm][maxm], s;

_ i_like_ya_cut_G(_ x, _ y, _ z);
_ gc();
int main() {
    
    memset(dp, (1<<7)^(1<<6), sizeof dp);
    scanf("%d", &n);
    for(_ i = 1; i <= n; ++i) a[i] = gc();
    dp[0][0][0][0][0] = 0;
    for(_ t = 1; t <= n; memset(dp[!(t&1)], (1<<7)^(1<<6), sizeof dp[!(t&1)]), ++t) for(_ i = 0; i <= 3; ++i) for(_ j = 0; j <= 3; ++j) for(_ k = 0; k <= 3; ++k) for(_ l = 0; l <= 3; ++l) {
        dp[t&1][j][a[t]][k][l] = max(dp[t&1][j][a[t]][k][l], dp[!(t&1)][i][j][k][l] + i_like_ya_cut_G(i, j, a[t]));
        dp[t&1][i][j][l][a[t]] = max(dp[t&1][i][j][l][a[t]], dp[!(t&1)][i][j][k][l] + i_like_ya_cut_G(k, l, a[t]));
    }
    for(_ i = 0; i <= 3; ++i) for(_ j = 0; j <= 3; ++j) for(_ k = 0; k <= 3; ++k) for(_ l = 0; l <= 3; ++l) s = max(s, dp[n&1][i][j][k][l]);
    printf("%d\n", s);
    
    return 0;
}

_ gc() {
    char ch = getchar();
    for(; ch != 'M' && ch != 'B' && ch != 'F'; ) ch = getchar();
    return ch == 'M' ? 1 : ch == 'F' ? 2 : 3;
}

_ i_like_ya_cut_G(_ x, _ y, _ z) {
    if((!x && !y) || (!y && !z) || (!x && !z)) return 1;
    if(!x) return (y != z) + 1;
    if(!y) return (x != z) + 1;
    if(!z) return (x != y) + 1;
    if(x == y && y == z) return 1;
    if(x == y || y == z || x == z) return 2;
    return 3;
}
