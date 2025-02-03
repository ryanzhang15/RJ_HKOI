
#include <cstdio>
#include <iostream>
#include <cstdlib>
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

constant maxn = 1E2+8;

_ t[8][4][4] = {{{}}, {{2, 2, 0, 0}, {2, 2, 0, 0}, {2, 2, 0, 0}, {2, 2, 0, 0}}, {{4, 0, 0, 0}, {1, 1, 1, 1}, {4, 0, 0, 0}, {1, 1, 1, 1}}, {{1, 3, 0, 0}, {1, 1, 2, 0}, {3, 1, 0, 0}, {2, 1, 1, 0}}, {{3, 1, 0, 0}, {1, 1, 2, 0}, {1, 3, 0, 0}, {2, 1, 1, 0}}, {{2, 2, 0, 0}, {1, 2, 1, 0}, {2, 2, 0, 0}, {1, 2, 1, 0}}, {{2, 2, 0, 0}, {1, 2, 1, 0}, {2, 2, 0, 0}, {1, 2, 1, 0}}, {{1, 2, 1, 0}, {3, 1, 0, 0}, {1, 2, 1, 0}, {1, 3, 0, 0}}}, g[maxn], n, m, k, x, y, z;

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &n, &m, &k);
    for(; k--; ) {
        scanf(_lllin, &x, &y, &z);
        for(_ i = z; i < z+4; ++i) g[i] += t[x][y/90][i-z];
    }
    
    x = *min_element(g+1, g+1+n);
    
    for(_ i = m; i >= 1; --i, putchar(10)) for(_ j = 1; j <= n; ++j) putchar(g[j]-x < i ? '.' : 'x');
    
    return 0;
}


