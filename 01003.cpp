#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 256+8;

_ n, hx, hy, s[maxn][maxn], c;
char o[maxn][maxn], t;
bitset<maxn> a;

void dfs(_ cx, _ cy, _ hx, _ hy, _ l);
int main() {
    scanf("%lld%lld%lld", &n, &hx, &hy);
    n = 1 << n;
    o[hx][hy] = '*';
    s[hx][hy] = -1;
    
    dfs(1, 1, hx, hy, n);
    
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j)    if(!o[i][j]) {
        a.reset();
        for(_ k = i-2; k <= i+2; ++k) for(_ l = j-2; l <= j+2; ++l) if(k >= 1 && k <= n && l >= 1 && l <= n) a[o[k][l]] = true;
        for(t = 'a'; t < 'z' && a[t]; ) ++t;
        for(_ k = i-1; k <= i+1; ++k) for(_ l = j-1; l <= j+1; ++l) if(s[i][j] == s[k][l]) o[k][l] = t;
    }
    
    for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) putchar(o[i][j]);
    
    return 0;
}

void dfs(_ cx, _ cy, _ hx, _ hy, _ l) {
    if(l == 2) {
        ++c;
        for(_ i = cx; i <= cx+1; ++i) for(_ j = cy; j <= cy+1; ++j) if(!(i == hx && j == hy)) s[i][j] = c;
        //        printf("Hole: %lld %lld\n", hx, hy);
        //        for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) printf("%lld", s[i][j]);
        return;
    }
    _ a = cx-1+(l>>1), b = cy-1+(l>>1);
    if(hx <= a && hy <= b) s[a][b+1] = s[a+1][b] = s[a+1][b+1] = ++c;
    ef(hx > a && hy <= b) s[a][b] = s[a][b+1] = s[a+1][b+1] = ++c;
    ef(hx <= a && hy > b) s[a][b] = s[a+1][b] = s[a+1][b+1] = ++c;
    else s[a][b] = s[a+1][b] = s[a][b+1] = ++c;
    
    for(_ i = cx; i <= a; ++i) for(_ j = cy; j <= b; ++j) if(s[i][j]) {
        dfs(cx, cy, i, j, l>>1);
        goto o1;
    }
o1:
    for(_ i = a+1; i <= cx+l-1; ++i) for(_ j = cy; j <= b; ++j) if(s[i][j]) {
        dfs(a+1, cy, i, j, l>>1);
        goto o2;
    }
o2:
    for(_ i = cx; i <= a; ++i) for(_ j = b+1; j <= cy+l-1; ++j) if(s[i][j]) {
        dfs(cx, b+1, i, j, l>>1);
        goto o3;
    }
o3:
    for(_ i = a+1; i <= cx+l-1; ++i) for(_ j = b+1; j <= cy+l-1; ++j) if(s[i][j]) {
        dfs(a+1, b+1, i, j, l>>1);
        goto o4;
    }
o4:
    return;
}
