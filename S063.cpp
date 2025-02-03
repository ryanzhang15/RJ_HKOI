
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, c[maxn][maxn], cnt, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, cs, s, bx, by, z[maxn*maxn], v[5], t;
char a[maxn][maxn], os;

inline void color(_ x, _ y);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf(" %s", a[i]+1);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(!c[i][j]) {
        ++cnt;
        color(i, j);
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) for(_ k = 0; k < 4; ++k) {
        _ nx = i + dx[k];
        _ ny = j + dy[k];
        if(nx <= 0 || ny <= 0 || nx > n || ny > n || c[nx][ny] == c[i][j]) continue;
        memset(v, ~0, sizeof v);
        cs = z[c[nx][ny]] + 1;
        t = 0;
        v[t++] = c[nx][ny];
        for(_ l = 0; l < 4; ++l) {
            _ nnx = i + dx[l];
            _ nny = j + dy[l];
            if(nnx <= 0 || nny <= 0 || nnx > n || nny > n) continue;
            if(a[nx][ny] == a[nnx][nny] && c[nnx][nny] != v[0] && c[nnx][nny] != v[1] && c[nnx][nny] != v[2]) {
                cs += z[c[nnx][nny]];
                v[t++] = c[nnx][nny];
            }
        }
        if(cs > s) {
            s = cs;
            bx = i;
            by = j;
            os = a[nx][ny];
        }
    }
    
    printf("%lld %lld %c\n%lld\n", bx, by, os, s);
    
    return 0;
}

inline void color(_ x, _ y) {
    c[x][y] = cnt;
    ++z[cnt];
    for(_ i = 0; i < 4; ++i) {
        _ nx = x + dx[i];
        _ ny = y + dy[i];
        if(nx <= 0 || ny <= 0 || nx > n || ny > n || c[nx][ny] || a[nx][ny] != a[x][y]) continue;
        color(nx, ny);
    }
    return;
}
