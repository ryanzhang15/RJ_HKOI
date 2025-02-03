#include <bits/stdc++.h>
#define ef else if
#define i(x) x::iterator
#define mp(x, y) make_pair(x, y)
#define v(x) vector<x > 

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

typedef long long ll;

constant maxn = 1E2+8;
constant maxm = 30+8;

_ n, m, sr, sc, dp[maxn][maxm][maxm], s = 1E17, ox, oy;
char a[maxn][maxm][maxm], b[maxn];
_p p[maxn][maxm][maxm];

void recur(_ x, _ y, _ z);
char gc();
int main() {

//#define file_IO
#ifdef file_IO
    freopen("data.in", "r", stdin);
#endif

    memset(dp, 4, sizeof dp);

    scanf("%lld%lld%lld%lld", &n, &m, &sr, &sc);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) for(_ k = 1; k <= m; ++k) a[i][j][k] = gc();
    for(_ i = 1; i <= n; ++i) b[i] = gc();
    dp[0][sr][sc] = 0;
    for(_ i = 1; i <= n; ++i) for(_ xa = 1; xa <= m; ++xa) for(_ ya = 1; ya <= m; ++ya) if(a[i][xa][ya] == b[i]) {
        //puts("gd");
        for(_ xb = 1; xb <= m; ++xb) for(_ yb = 1; yb <= m; ++yb) if(dp[i-1][xb][yb] < 1E11) if(dp[i-1][xb][yb]+abs(xa-xb)+abs(ya-yb) < dp[i][xa][ya]) {
            dp[i][xa][ya] = dp[i-1][xb][yb]+abs(xa-xb)+abs(ya-yb);
            p[i][xa][ya] = make_pair(xb, yb);
        }
    }
    //for(_ i = 0; i <= n; ++i) for(_ j = 1; j <= m; ++j) for(_ k = 1; k <= m; ++k) {
        //printf("i = %lld, j = %lld, k = %lld, dp[i][j][k] = %lld\n", i, j, k, dp[i][j][k]);
    //}
    for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= m; ++j) if(dp[n][i][j] < s) {
        //printf("i = %lld, j = %lld, dpv = %lld\n", i, j, dp[n][i][j]);
        s = dp[n][i][j];
        ox = i;
        oy = j;
    }
    printf("%lld\n", s);
    recur(n, ox, oy);
    
    return 0;
}

char gc() {
    char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
    return ch;
}

void recur(_ x, _ y, _ z) {
    if(!x) return;
    recur(x-1, p[x][y][z].first, p[x][y][z].second);
    printf("%lld %lld\n", y, z);
    return;
}