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

constant maxn = 1E2+8;
_ d[maxn][maxn], n, m, q, a, b;

int main(int argc, char * argv[]) {
    
    memset(d, 0x7F, sizeof d);
    scanf(_lllin, &n, &m, &q);
    for(; m--; ) {
        scanf(_llin, &a, &b);
        scanf(_lin, &d[a][b]);
        d[b][a] = d[a][b];
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) for(_ k = 1; k <= n; ++k) d[j][k] = min(d[j][k], max(d[j][i], d[i][k]));
    for(; q--; ){
        scanf(_llin, &a, &b);
        if(d[a][b] == d[maxn-1][maxn-1]) puts("no path");
        else printf(fs(_l+"\n"), d[a][b]);
    }
    
    
    return 0;
}
