#pragma g++ optimize("Ofast")

#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef int _;
typedef pair<_, _> _p;
typedef string str;
typedef long double _D;
typedef const long long constant;
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}
constant maxn = 1E3+8;

_ n, a[maxn], b[maxn], sm, pc, s, t[maxn][4];
bool fs, sn, od;
vector<_> g, h;

int main() {

#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
#ifdef c8korz
    freopen("c8k.out" ,"w", stdout);
#endif

    memset(t, ~0, sizeof t);

    n = read();
    for(_ i = 1; i <= n; ++i) {
        b[i] = read();
        if(b[i] == -2 && i == 1) fs = true;
        if(b[i] == -2) sn = true;
        if(!sn) pc += b[i];
        if(b[i] != -2) sm += b[i];
    }
    for(_ i = 1; i <= n; ++i) {
        a[i] = read();
        if(a[i] & 1) od = true;
        if(a[i] != -2) sm += a[i];
    }
    if(fs || (pc & 1) || od) {
        printf("%d\n", sm);
        exit(0);
    }
    sort(a+1, a+1+n);
    for(_ i = 1; i <= n; ++i) if(b[i] != -2) {
        _ c = 0, p = 1;
        for(_ j = 1; j <= n; ++j) {
            if(b[j] == -2) c = c & 1 ? c : c >> 1;
            else c += b[j];
            if(j == i) c = c & 1 ? c : c >> 1;
            else c += a[++p];
        }
        s = max(s, c);
    }
    g.push_back(0);
    h.push_back(0);
    for(_ i = 2; i <= n; ++i) if(a[i] & 3) g.push_back(a[i]);
    else h.push_back(a[i]);
    for(_ i = 1; i < g.size(); ++i) g[i] += g[i-1];
    for(_ i = 1; i < h.size(); ++i) h[i] += h[i-1];
    for(_ i = 0; i < g.size(); ++i) for(_ j = 0; j < h.size(); ++j) {
        _ sm = g[i]+h[j];
        t[i+j][sm & 3] = ~t[i+j][sm & 3] ? min(t[i+j][sm & 3], sm) : sm;
    }
    _ rt = 0;
    for(_ i = 2; i <= n; ++i) rt += a[i];
    for(_ i = 1; i <= n; ++i) if(b[i] == -2) {
        _ c = 0, d = 0, nd;
        for(_ j = 1; j <= i-1; ++j) c += b[j];
        for(_ j = i+1; j <= n; ++j) d += b[j];
        nd = c & 3 ? 0 : 2;
        if(~t[i-1][nd]) s = max(s, ((c+t[i-1][nd])>>1)+d+rt-t[i-1][nd]);
        break;
    }
    _ ot = 0;
    for(_ i = 1; i <= n; ++i) if(b[i] != -2) ot += b[i];
    for(_ i = 1, c = 0; b[i] != -2; ++i) {
        c += b[i];
        if(c & 1) continue;
        _ nd = c & 3 ? 0 : 2;
        if(~t[i-1][nd]) s = max(s, ((c+t[i-1][nd])>>1)+rt-t[i-1][nd]+ot-c);
    }
    printf("%d\n", s);

    return 0;
}

