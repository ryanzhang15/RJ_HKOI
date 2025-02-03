#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E4+8;

vector<_> g[maxn];
_ n, dp[maxn][5], x, y;

void run(_ x, _ f);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= 4; ++j) dp[i][j] = j;
    for(_ i = 1; i <= n-1; ++i) {
        scanf("%lld%lld", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    run(1, -1);
    printf("%lld\n", min(min(dp[1][1], dp[1][2]), min(dp[1][3], dp[1][4])));
    
    return 0;
}

void run(_ x, _ f) {
    for(_ i = 0; i < g[x].size(); ++i) if(g[x][i] != f) {
        run(g[x][i], x);
        for(_ j = 1; j <= 4; ++j) {
            _ mv = 1E18;
            for(_ k = 1; k <= 4; ++k) if(j != k) mv = min(mv, dp[g[x][i]][k]);
            dp[x][j] += mv;
        }
    }
    return;
}
