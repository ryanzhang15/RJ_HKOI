#include <cstdio>
#include <cstring>
#include <algorithm>
#define ef else if

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E2+8;
_ n, m, d[maxn][maxn], nc[maxn][maxn], x, y, c, s = 1E14;

inline _ read();
int main(int argc, char * argv[]) {

    memset(d, 4, sizeof d);
    memset(nc, 4, sizeof nc);
    
    n = read();
    m = read();
    for(register _ i = 1; i <= n; ++i) d[i][i] = nc[i][i] = 0;
    for(; m--; ) {
        x = read();
        y = read();
        c = read();
        d[x][y] = d[y][x] = nc[x][y] = nc[y][x] = c;
    }
    for(_ k = 1; k <= n; ++k) {
        for(_ i = 1; i < k; ++i) for(_ j = i+1; j < k; ++j) s = min(s, d[i][j]+nc[i][k]+nc[k][j]);
        for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }
    
    printf("%lld\n", s);

    return 0;
}

inline _ read() {
    int x=0;char ch=getchar_unlocked();
    while (!(ch >= '0' && ch <= '9')){ch=getchar_unlocked();}
    while (ch >= '0' && ch <= '9'){x=x*10+ch-48;ch=getchar_unlocked();}
    return x;
}
