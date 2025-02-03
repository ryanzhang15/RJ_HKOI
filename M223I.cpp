
#pragma G++ optimize("Ofast")

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <bitset>
#include <string>
#include <stack>
#include <unordered_set>
#include <vector>
#include <map>

#define ef else if
#define mp(x, y) make_pair(x, y)
#define pr(x, y) pair< x, y >

using namespace std;

typedef int _;
typedef long long ll;
typedef int _0;
typedef double _D;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

inline _ read() {
    _ x = 0, d = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') d *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*d;
}

inline void read(str & a) {
    a.clear();
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ) ch = getchar();
    for(; !(ch == ' ' || ch == '\n' || ch == EOF); ch = getchar()) a += ch;
    return;
}

inline void read(char * a) {
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ) ch = getchar();
    for(; !(ch == ' ' || ch == '\n' || ch == EOF); ch = getchar()) {
        *a = ch;
        ++a;
    }
    *a = '\0';
    return;
}

constant maxn = 3E3+8;

_ n, m, a[maxn], x, y, mx[maxn][2];
ll dp[maxn][maxn][2];
v_ g[maxn];

inline void dfs(_ x, _ fa);
int main() {
    
    memset(dp, -4, sizeof dp);
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = n; --i; ) {
        x = read();
        y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    ll s = 0;
    for(_ i = 0; i <= m; ++i) s = max(s, max(dp[1][i][0], dp[1][i][1]));
    printf("%lld\n", s);
     
    return 0;
}

inline void dfs(_ x, _ fa) {
    dp[x][1][1] = a[x];
    dp[x][0][0] = 0;
    mx[x][0] = 0;
    mx[x][1] = 1;
    for(_ i : g[x]) if(i != fa) {
        dfs(i, x);
        _ tj = min(m, max(mx[x][0], mx[x][1]));
        for(_ j = tj; j >= 0; --j) {
            _ tk = min(m, max(mx[i][0], mx[i][1]));
            for(_ k = tk; k >= 0; --k) {
                dp[x][j+k][0] = max(dp[x][j+k][0], dp[x][j][0]+max(dp[i][k][1], dp[i][k][0]));
                dp[x][j+k][1] = max(dp[x][j+k][1], dp[x][j][1]+dp[i][k][0]);
            }
        }
        mx[x][0] += max(mx[i][1], mx[i][0]);
        mx[x][1] += mx[i][0];
    }
    return;
}


