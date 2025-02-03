#ifndef __cplusplus
#include <stdbool.h>
#else
extern "C" {
#endif
void chooseCorridor(int x);
void placeFlag();
void removeFlag();
int countFlags();
bool detectDeadEnd();

void reportRooms(int N);
void reportCorridor(int u, int v);

void explore(int maxN, int L, int F, bool D);
#ifdef __cplusplus
}
#endif

#include <cstdlib>
#include <cstdio>
#include <vector>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;

int n = 1, sz[maxn], cnt, ccc, sv[maxn], pt[maxn];
vector<int> g[maxn];

void cc(int x) {
    if(++cnt > 3e4) exit(1);
    chooseCorridor(x);
    return;
}

_ cf() {
    if(++ccc > 3e4) exit(2);
    return countFlags();
}

void cave(_ x);
void explore(int maxN, int L, int F, bool D) {
    
    cave(1);
    reportRooms(n);
    for(int i = 1; i <= n; ++i) for(int j : g[i]) reportCorridor(i, j);
    
    return;
}

void cave(_ x) {
    placeFlag();
    cc(1);
    placeFlag();
    _ cv = 0;
    g[x].push_back(++n);
    sz[n] = 0;
    for(;;) {
        if(cf()) ++cv;
        else cv = 0;
        if(cv == 2) break;
        ++sz[n];
        cc(1);
    }
    --sz[n];
    for(;;) {
        cc(1);
        if(countFlags()) {
            removeFlag();
            for(; !cf(); ) cc(1);
            if(x != 1) --n;
            break;
        }
        g[x].push_back(++n);
        for(; ; ++sz[n]) {
            cc(1);
            if(cf()) break;
        }
    }
    removeFlag();
    pt[x] = 0;
    _ tp = n;
    for(int i = 1; i < g[x].size(); ++i) if((x == 1 || g[x][i] <= tp) && sz[g[x][i]]) {
        cc(i-pt[x]);
        pt[x] = i;
        cave(g[x][i]);
        cc(sv[g[x][i]]);
    }
    if(sz[g[x][0]]) {
        cc((int)g[x].size()-pt[x]);
        pt[x] = 0;
        cave(g[x][0]);
        cc(sv[g[x][0]]);
    }
    sv[x] = (int)(2*g[x].size())-pt[x]-1;
    if(x != 1) g[x].pop_back();
    return;
}

#ifndef ONLINE_JUDGE

constant mmaxn = 1E2+8;

vector<_> gg[mmaxn];
_ p = 1, xx, yy, nn, r[maxn], flg[maxn];

int main() {
    
    r[1] = -1;
    scanf("%lld", &nn);
    for(_ i = nn; --i; ) {
        scanf("%lld%lld", &xx, &yy);
        gg[xx].push_back(yy);
        gg[yy].push_back(xx);
    }
    explore(1, 1, 1, false);
    
    return 0;
}

void chooseCorridor(int x) {
    _ cf = p;
    r[p] = (r[p]+x)%gg[p].size();
    p = gg[p][r[p]];
    for(; gg[p][r[p]] != cf; ) r[p] = (r[p]+1)%gg[p].size();
    return;
}

void placeFlag() {
    ++flg[p];
    return;
}

void removeFlag() {
    --flg[p];
    return;
}

int countFlags() {
    return (int)flg[p];
}

bool detectDeadEnd() {
    return true;
}

void reportRooms(int N) {
    printf("reported %d, correct answer was %lld.\nUsed %d queries.\n", N, nn, max(cnt, ccc));
    return;
}

void reportCorridor(int u, int v) {
    printf("corridor reported: %d %d\n", u, v);
    return;
}

#endif


