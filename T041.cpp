
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
#include <random>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
const std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;
typedef pair<_, _> _p;

constant maxn = 1E2+8;
_ dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, sx, sy, sdir, n, ex, ey, c;
_p v[maxn][maxn][10];
stack<char> o;
char a[maxn][maxn], d;
bool flag;

_ h(_ x, _ y);
inline void dfs(_ s, _ x, _ y, _ dir);
int main() {
    
    //freopen("/Users/ryan/Desktop/in.txt", "r", stdin);
    
    for(_ i = 0; i < maxn; ++i) for(_ j = 0; j < maxn; ++j) for(_ k = 0; k < 4; ++k) v[i][j][k].first = 1E10;
    
    //IDA* ?
    scanf(_lin, &n);
    getchar();
    for(_ i = 1; i <= n; ++i, getchar()) for(_ j = 1; j <= n; ++j) {
        a[i][j] = getchar();
        if((a[i][j]) == 'B') {
            sx = i;
            sy = j;
        } ef(a[i][j] == 'A') {
            ex = i;
            ey = j;
        }
    }
    d = getchar();
    switch (d) {
        case 'N':
            sdir = 0;
            break;
        case 'E':
            sdir = 1;
            break;
        case 'S':
            sdir = 2;
            break;
        case 'W':
            sdir = 3;
            break;
    }
    
    v[sx][sy][sdir] = {0, 0};
    for(c = 1; !flag; ++c) {
        dfs(1, sx, sy, sdir);
    }
    for(; !o.empty(); o.pop()) {
        putchar(o.top());
        putchar(10);
    }
    
    return 0;
}

inline void dfs(_ s, _ x, _ y, _ dir) {
    if(s + h(x, y) > c) return;
    //turn
    if(v[x][y][(dir+1)%4].first > s || v[x][y][(dir+1)%4].second != c) {
        v[x][y][(dir+1)%4] = {s, c};
        dfs(s+1, x, y, (dir+1)%4);
        if(flag) {
            o.push('T');
            return;
        }
    }
    //move
    _ nx = x + dx[dir];
    _ ny = y + dy[dir];
    if(nx <= 0 || ny <= 0 || nx > n || ny > n || a[nx][ny] == '1') return;
    if(nx == ex && ny == ey) {
        printf(fs(_l+"\n"), s);
        o.push('M');
        flag = true;
        return;
    }
    if(v[nx][ny][dir].first > s || v[nx][ny][dir].second != c) {
        v[nx][ny][dir] = {s, c};
        dfs(s+1, nx, ny, dir);
        if(flag) {
            o.push('M');
            return;
        }
    }
    
    return;
}

_ h(_ x, _ y) {
    /*_*/
    return abs(ex-x) + abs(ey-y);
}
