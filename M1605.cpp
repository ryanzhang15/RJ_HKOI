#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, m, s;
bool a[maxn][maxn];
char ch;

void clear(_ x, _ y, _ s1, _ s2f);
void check(_ x, _ y);
bool getBool();
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] = getBool();
    for(_ i = 1; i <= n-1; ++i) for(_ j = 1; j <= m-1; ++j) if(a[i][j] && a[i+1][j] && a[i][j+1] && !a[i+1][j+1]) check(i, j);
    printf("%lld\n", s);
    
    return 0;
}

bool getBool() {
    ch = getchar();
    for(; ch != '#' && ch != '.'; ) ch = getchar();
    return ch == '#';
}

void check(_ x, _ y) {
    _ h = 1, w = 1;
    for(_ i = x+1; !(a[i][y] && a[i][y+1]); ++i) ++h;
    for(_ i = y+1; !(a[x][i] && a[x+1][i]); ++i) ++w;
    h = (h<<1)+1;
    w = (w<<1)+1;
    s = max(s, h*w);
    clear(x, y, h, w);
    return;
}

void clear(_ x, _ y, _ s1, _ s2) {
    for(_ i = x; i <= x+s1-1; ++i) for(_ j = y; j <= y+s2-1; ++j) a[i][j] = false;
    return;
}
