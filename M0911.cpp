
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
//#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 20+8;

_ n, m, dx[] = {0, 1, 0, -1, 0}, dy[] = {-1, 0, 1, 0, 0}, c[maxn][maxn], cd, v[maxn][maxn][maxn][maxn];
bool o;
char dir[] = "LDRUS";
pair<_, _> th, mn;
stack<char> out;

bool moveMin(_ &x, _ &y, _ ox, _ oy);
void dfs(_ tx, _ ty, _ mx, _ my, _ d);
int main(int argc, char * argv[]) {
    
    memset(v, 4, sizeof v);
    scanf(_ll, &m, &n);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf(_lin, &c[i][j]);
    scanf(_llll, &mn.first, &mn.second, &th.first, &th.second);
    v[th.first][th.second][mn.first][mn.second] = 0;
    for(cd = 1; !o; ++cd) dfs(th.first, th.second, mn.first, mn.second, 1);
    for(; !out.empty(); out.pop()) {
        putchar(out.top());
        putchar(10);
    }
    
    return 0;
}

void dfs(_ tx, _ ty, _ mx, _ my, _ d) {
    if(d > cd) return;
    for(_ i = 0; i < 5; ++i) {
        if(i != 5 && c[tx][ty] & (1 << i)) continue;
        _ nx = tx + dx[i];
        _ ny = ty + dy[i];
        if(nx <= 0 || ny <= 0 || nx > n || ny > m) {
            printf(fs(_l+"\n"), d);
            o = true;
            out.push(dir[i]);
            return;
        }
        _ nmx = mx;
        _ nmy = my;
        bool a = moveMin(nmx, nmy, nx, ny);
        a |= moveMin(nmx, nmy, nx, ny);
        if(v[nx][ny][nmx][nmy] < d) continue;
        v[nx][ny][nmx][nmy] = d;
        if(!a) dfs(nx, ny, nmx, nmy, d+1);
        if(o) {
            out.push(dir[i]);
            return;
        }
    }
    return;
}

bool moveMin(_ &x, _ &y, _ ox, _ oy) {
    if(x == ox && y == oy) return true;
    if(y < oy && !(c[x][y] & 4)) {
        ++y;
        return (x == ox && y == oy);
    }
    if(y > oy && !(c[x][y] & 1)) {
        --y;
        return (x == ox && y == oy);
    }
    if(x < ox && !(c[x][y] & 2)) {
        ++x;
        return (x == ox && y == oy);
    }
    if(x > ox && !(c[x][y] & 8)) {
        --x;
        return (x == ox && y == oy);
    }
    return false;
}
