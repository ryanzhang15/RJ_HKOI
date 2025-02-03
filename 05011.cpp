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
constant maxm = 1E4+8;

_ n, m, f[maxn][maxm], a[maxn], c[maxn];

int main(int argc, char * argv []) {

    memset(f, 0x7F, sizeof f);
    scanf(_llin, &m, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(_lin, &a[i]);
        f[i][0] = 0;
        for(_ j = a[i]; j <= m; ++j) f[i][j] = min(f[i-1][j], f[i][j-a[i]]+1);
    }
    _ i = n, j = m;
    for(; i && j; )
        if(f[i][j] == f[i-1][j]) --i;
        else {
            ++c[i];
            j -= a[i];
        }
    
    printf(fs(_l+"\n"), f[n][m]);
    for(_ i = 1; i <= n; ++i) printf(fs(_l+"\n"), c[i]);
    
    return 0;
}
