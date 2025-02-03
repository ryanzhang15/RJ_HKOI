
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

constant maxn = 5E5+8;
constant maxm = 5E4+8;
constant maxk = 1E3+8;

struct cart {
    _ wth, vlm;
    void get() {
        scanf(_llin, &wth, &vlm);
    }
} c[maxm];
_ n, m, g[maxn], l[maxk];

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &g[i]);
    for(_ i = 1; i <= m; ++i) c[i].get();
    for(_ i = 1; i <= n; ++i) {
        for(; l[g[i]] <= m && (g[i] > c[l[g[i]]].wth || g[i] > c[l[g[i]]].vlm); ) ++l[g[i]];
        if(l[g[i]] > m) {
            puts("Impossible");
            exit(0);
        }
        c[l[g[i]]].vlm -= g[i];
        g[i] = l[g[i]];
    }
    for(_ i = 1; i <= n; ++i) printf(fs(_l+" "), g[i]);
    putchar(10);
    
    return 0;
}
