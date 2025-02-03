
#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")

#include <cstdio>
#define mod 7022117
#define up 71

typedef int _;

_ n, m, k[7], p[7], s, a[mod], b[mod], po[151][5];

inline void dfs2(_ d, _ cs);
inline void dfs1(_ d, _ s);
inline int hassh(_ x);
//inline int read();
int main(int argc, char ** argv) {
    
    scanf("%d%d", &n, &m);
    for(register _ i = 1; i <= m; ++i) for(register _ j = 0; j <= 4; ++j) po[i][j] = j ? po[i][j-1]*i : 1;
    for(register _ i = 1; i <= n; ++i) scanf("%d%d", &k[i], &p[i]);
    dfs1(1, 0);
    dfs2((n>>1)+1, 0);
    printf("%d\n", s);

    return 0;
}

//inline int read()
//{
//    int x=0,f=1;char ch=getchar_unlocked();
//    while (!(ch >= '0' && ch <= '9')){if (ch=='-') f=-1;ch=getchar_unlocked();}
//    while (ch >= '0' && ch <= '9'){x=x*10+ch-48;ch=getchar_unlocked();}
//    return x*f;
//}

inline int hassh(_ x) {
    _ hv = ((x%mod)+mod)%mod;
    for(; a[hv] && b[hv] != x; ) hv = hv+up >= mod ? (hv+up)%mod : hv+up;
    return hv;
}

inline void dfs1(_ d, _ s) {
    if(d > (n>>1)) {
        _ hv = hassh(s);
        ++a[hv];
        b[hv] = s;
        return;
    }
    for(register _ i = 1; i <= m; ++i) dfs1(d+1, s+k[d]*po[i][p[d]]);
    return;
}

inline void dfs2(_ d, _ cs) {
    if(d > n) {
        s += a[hassh(cs)];
        return;
    }
    for(register _ i = 1; i <= m; ++i) dfs2(d+1, cs-k[d]*po[i][p[d]]);
    return;
}
