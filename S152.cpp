
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxk = 4E3+8;
//constant maxk = 5;

_ n, m, k, d[maxk], p[maxk][maxk], in[maxk][2], cnt, t = 1, c, s;
struct rg {
    _ l, r;
} r[maxk];

int main() {
    
    scanf("%lld%lld%lld", &n, &m, &k);
    for(_ i = 1; i <= k; ++i) {
        scanf("%lld%lld", &in[i][0], &in[i][1]);
        d[++cnt] = in[i][0];
        d[++cnt] = in[i][1];
    }
    sort(d+1, d+1+cnt);
    cnt = unique(d+1, d+1+cnt)-d-1;
    for(_ i = 1; i <= k; ++i) {
        in[i][0] = lower_bound(d+1, d+1+cnt, in[i][0])-d;
        in[i][1] = lower_bound(d+1, d+1+cnt, in[i][1])-d;
        p[in[i][0]][in[i][1]] = 1;
    }
    k = cnt;
    for(_ i = 2; i <= k; ++i) for(_ j = 1; j <= k; ++j) p[i][j] += p[i-1][j];
    for(_ i = 1; i <= k; ++i) for(_ j = 2; j <= k; ++j) p[i][j] += p[i][j-1];
    for(_ i = 1; i <= k; ++i) {
        for(; d[i]-d[t] >= m; ) ++t;
        r[i] = (rg){t, i};
    }
    for(_ i = 1; i <= k; ++i) for(_ j = 1; j <= k; ++j) {
        _ xa = r[i].l, ya = r[j].l, xb = r[i].r, yb = r[j].r;
        s = max(s, p[xb][yb]-p[xa-1][yb]-p[xb][ya-1]+p[xa-1][ya-1]);
    }
    printf("%lld\n", s);
    
    return 0;
}

