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
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
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

constant maxn = 1E2+8;
//constant maxn = 15;

_ n, m, k, d, t, as, ax, ay;

struct rg {
    _ x, y, v;
    bool inD(_ x1, _ y1) {
        return abs(x1-x) + abs(y1-y) <= d;
    }
} a[maxn*10];

void dfs(_ x, _ y, _ s);
int main(int argc, char * argv[]) {
    
    scanf(_llllin, &n, &m, &k, &d);
    for(_ i = 1; i <= k; ++i) scanf(_lllin, &a[i].x, &a[i].y, &a[i].v);
    for(_ i = 1; i <= n; ++i)
        for(_ j = 1; j <= m; ++j) {
            t = 0;
            for(_ l = 1; l <= k; ++l) if(a[l].inD(i, j)) t += a[l].v;
            if(t > as) {
                as = t;
                ax = i;
                ay = j;
            }
        }
    
    printf(fs(_l+" "+_l+" "+_l+"\n"), ax, ay, as);
    
    return 0;
}
