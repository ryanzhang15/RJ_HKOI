
#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _l "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string l_ = _l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 2E2+8;
struct node {
    _ x, y;
};
_ n, m, c, g[maxn][maxn], sx, sy, ax, ay, x, y, s, t, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool v[maxn][maxn], seen;
queue<node> q;

_ bfs(_ va);
int main(int argc, char * argv[]) {
    
    scanf(_lll, &n, &m, &c);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf(_l, &g[i][j]);
    scanf(_ll, &sx, &sy);
    for(_ i = g[sx][sy]-c; i <= g[sx][sy]+c; ++i) {
        _ cb = bfs(i);
        if(cb > s || (cb == s && (ax < x || (ax == x && ay < y)))) {
            x = ax;
            y = ay;
            s = bfs(i);
        }
    }
    
    printf(fs(l_+" "+l_+" "+l_+"\n"), x, y, s);
     
    return 0;
}

_ bfs(_ va) {
    if(va < 0) return 0;
    for(; !q.empty(); ) q.pop();
    t = seen = 0;
    memset(v, false, sizeof v);
    q.push({sx, sy});
    ++t;
    v[sx][sy] = true;
    ax = ay = 1E12;
    for(; !q.empty(); q.pop()) for(_ i = 0; i < 4; ++i) {
        _ nx = q.front().x + dx[i];
        _ ny = q.front().y + dy[i];
        if(nx <= 0 || ny <= 0 || nx > n || ny > m || v[nx][ny] || abs(g[nx][ny]-va) > c) continue;
        if(g[nx][ny] == va) {
            seen = true;
            if(nx < ax) {
                ax = nx;
                ay = ny;
            } else if(nx == ax && ny < ay) ay = ny;
        }
        ++t;
        v[nx][ny] = true;
        q.push({nx, ny});
    }
    return t*seen;
}
