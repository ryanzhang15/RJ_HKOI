
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
//#include <unordered_map>
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

constant maxn = 1E3+8;

_ n, m, p, r, l, c[maxn], s;
char a[maxn][maxn], e[maxn][maxn], t;
short pr[maxn][maxn][100];
_D x, y;

int main(int argc, char * argv[]) {
    
    scanf(_lllll, &n, &m, &p, &r, &l);
    for(_ i = 1; i <= p; ++i) scanf(_lin, &c[i+'A'-1]);
    getchar();
    for(_ i = m; i >= 1; --i, getchar()) for(_ j = 1; j <= n; ++j) a[i][j] = getchar();
    for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= n; ++j) for(char k = 'A', ctr = 1; ctr <= p; ++k, ++ctr) pr[i][j][k] = (k == a[i][j]) ? pr[i][j-1][k]+1 : 0;
    for(_ i = 1; i + l - 1 <= m; ++i) for(_ j = 1; j + l - 1 <= n; ++j) {
        t = a[i][j];
        for(_ x = i; x <= i+l-1; ++x) if(pr[x][j+l-1][t] < l) {
            t = '\0';
            break;
        }
        e[i][j] = t;
    }
    
    for(; r--; ) {
        scanf("%Lf%Lf", &y, &x);
        ++x;
        ++y;
        if(x < 1 || y < 1 || x > m || y > n) continue;
        if(e[(_)x][(_)y] == e[(_)ceil(x)][(_)y] && e[(_)x][(_)y] == e[(_)x][(_)ceil(y)] && e[(_)x][(_)y] == e[(_)ceil(x)][(_)ceil(y)]) s += c[e[(_)x][(_)y]];
    }
    
    printf("%lld\n", s);
    
    return 0;
}


