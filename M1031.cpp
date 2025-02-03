
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
#include <unordered_map>
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E2+8;
constant maxk = 20+8;

_ n, m, k, u[maxn][maxn], b[maxn], mx[maxn], s, t[maxk], c[maxk], x, y, r[maxk][maxn][2], v[maxn];

void dfs(_ x, _ ca);
int main(int argc, char * argv[]) {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) {
        mx[i] = -1E18;
        for(_ j = 1; j <= m; ++j) {
            scanf("%lld", &u[i][j]);
            mx[i] = max(mx[i], u[i][j]);
        }
    }
    scanf("%lld", &k);
    for(_ i = 1; i <= k; ++i) {
        scanf("%lld%lld", &c[i], &t[i]);
        for(_ j = 1; j <= c[i]; ++j) scanf("%lld%lld", &r[i][j][0], &r[i][j][1]);
    }
    dfs(1, 0);
    printf("%lld\n", s);
    return 0;
}

void dfs(_ x, _ ca) {
    if(x > k) {
        _ sm = 0;
        for(_ i = 1; i <= n; ++i) sm += v[i] ? u[i][b[i]] : mx[i];
        s = max(s, sm+ca);
        return;
    }
    dfs(x+1, ca);
    bool ok = true;
    for(_ i = 1; i <= c[x]; ++i) {
        if(v[r[x][i][0]]++ && b[r[x][i][0]] != r[x][i][1]) ok = false;
        b[r[x][i][0]] = r[x][i][1];
    }
    if(ok) dfs(x+1, ca+t[x]);
    for(_ i = 1; i <= c[x]; ++i) --v[r[x][i][0]];
    return;
}

