
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
#include <queue>
#include <list>
#include <set>

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

_ n, m, dp[2][maxn], t, l = 1, c, s = -1E14, b, f[maxn][maxn], p, lp;
stack<_> ns;

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    dp[1][0] = dp[0][0] = -1E14;
    for(_ i = 1; i <= n; ++i, t ^= 1, l ^= 1, b = -1E14)
        for(_ j = 1; j <= m; ++j) {
            scanf(_lin, &c);
            if(j >= i) {
                dp[t][j] = c+b;
                f[i][j] = p;
                if(i == n)
                    if(dp[t][j] > s) {
                        s = dp[t][j];
                        lp = j;
                        
                    }
            } else dp[t][j] = -1E14;
            if(dp[l][j] > b) {
                b = dp[l][j];
                p = j;
            }
        }
    
    printf(fs(_l+"\n"), s);
    for(_ i = n, j = lp; i; j = f[i][j], i--) {
        ns.push(j);
    }
    for(; !ns.empty(); ns.pop()) printf(fs(_l+" "), ns.top());
    putchar(10);
    
    return 0;
}

