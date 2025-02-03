
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
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 8E2+8;
_ n, m, x, y, sx, sy, tx, ty;
char g[maxn][maxn];
pair<_, _> c[maxn*maxn];

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; ++i) {
        getchar();
        for(_ j = 1; j <= m; ++j) g[i][j] = getchar();
    }
    for(_ i = 1; i < n*m; ++i) {
        scanf(_llin, &c[i].first, &c[i].second);
        tx += c[i].first;
        ty += c[i].second;
        sx = max(tx, sx);
        sy = max(ty, sy);
    }
    x = n-sx;
    y = m-sy;
    for(_ i = 1; i <= n*m; ++i) {
        putchar(g[x][y]);
        x += c[i].first;
        y += c[i].second;
    }
    
    putchar(10);
    
    return 0;
}
