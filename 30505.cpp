
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E2+8;

_ n, m, col[maxn], t, s, o;
vector<_> g[maxn];
bool k;

void bi(_ x, _ c);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &m);
        for(; m--; ) {
            scanf("%lld", &t);
            if(t > n) continue;
            g[i].push_back(t);
            g[t].push_back(i);
        }
    }
    
    for(_ i = 1; i <= n; ++i) if(!col[i]) {
        t = s = k = 0;
        bi(i, 1);
        if(!k) o += max(s, t-s);
    }
    
    printf("%lld\n", o);
    
    return 0;
}

void bi(_ x, _ c) {
    col[x] = c;
    ++t;
    if(c == 1) ++s;
    for(_ i = 0; i < g[x].size(); ++i) {
        if(!col[g[x][i]]) bi(g[x][i], -c);
        else if(col[g[x][i]] == c) k = true;
    }
    return;
}
