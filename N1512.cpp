#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, c, q, cnt, t[maxn<<2], lz[maxn<<2], d[maxn], size[maxn], fa[maxn], son[maxn], top[maxn], id[maxn], s;
bool st[maxn];
vector<_> g[maxn];
char tc;

void installRange(_ x);
void update(_ l, _ r, _ L, _ R, bool k, _ rt);
void pushDown(_ rt, _ sz);
void pushUp(_ rt);
void dfs2(_ x, _ tpf);
void dfs1(_ x, _ f, _ dpth);
char getCmd();
int main() {
    
    scanf("%lld", &n);
    for(_ i = 2; i <= n; ++i) {
        scanf("%lld", &c);
        g[c+1].push_back(i);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    scanf("%lld", &q);
    for(; q--; s = 0) {
        tc = getCmd();
        scanf("%lld", &c);
        ++c;
        if(tc == 'i') installRange(c);
        else update(1, n, id[c], id[c]+size[c]-1, false, 1);
        printf("%lld\n", s);
    }
    return 0;
}

char getCmd() {
    char c = getchar();
    for(; c != 'u' && c != 'i'; ) c = getchar();
    for(char d = getchar(); d != ' '; ) d = getchar();
    return c;
}

void dfs1(_ x, _ f, _ dpth) {
    d[x] = dpth;
    size[x] = 1;
    fa[x] = f;
    _ ms = -1E14;
    for(_ i = 0; i < g[x].size(); ++i) {
        dfs1(g[x][i], x, dpth+1);
        if(size[g[x][i]] > ms) {
            ms = size[g[x][i]];
            son[x] = g[x][i];
        }
        size[x] += size[g[x][i]];
    }
    return;
}

void dfs2(_ x, _ tpf) {
    id[x] = ++cnt;
    top[x] = tpf;
    if(!son[x]) return;
    dfs2(son[x], tpf);
    for(_ i = 0; i < g[x].size(); ++i) {
        if(g[x][i] == son[x]) continue;
        dfs2(g[x][i], g[x][i]);
    }
    return;
}

void pushUp(_ rt) {
    t[rt] = t[rt<<1]+t[rt<<1|1];
    return;
}

void pushDown(_ rt, _ sz) {
    lz[rt<<1] = lz[rt];
    lz[rt<<1|1] = lz[rt];
    if(!~lz[rt]) t[rt<<1] = t[rt<<1|1] = 0;
    ef(lz[rt]) {
        t[rt<<1] = (sz+1)>>1;
        t[rt<<1|1] = sz>>1;
    }
    lz[rt] = 0;
    return;
}

void update(_ l, _ r, _ L, _ R, bool k, _ rt) {
    if(L <= l && r <= R) {
        if(k) {
            lz[rt] = 1;
            s += (r-l+1-t[rt]);
            t[rt] = r-l+1;
        } else {
            lz[rt] = -1;
            s += t[rt];
            t[rt] = 0;
        }
        return;
    }
    if(lz[rt]) pushDown(rt, r-l+1);
    _ m = (l+r)>>1;
    if(L <= m) update(l, m, L, R, k, rt<<1);
    if(R > m) update(m+1, r, L, R, k, rt<<1|1);
    pushUp(rt);
    return;
}

void installRange(_ x) {
    for(; x; ) {
        update(1, n, id[top[x]], id[x], true, 1);
        x = fa[top[x]];
    }
    return;
}



