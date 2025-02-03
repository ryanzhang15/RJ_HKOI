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

constant maxn = 2E5+88;
//constant maxn = 20;
_ dp[maxn][2], a[maxn], n, s, b[maxn][2];

int main(int argc, char * argv []) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &a[i]);
    for(_ i = 1; i <= n; ++i) dp[i][0] = max(dp[i-1][0], dp[i][0]) + a[i];
    for(_ i = 1; i <= n; ++i) b[i][0] = max(b[i-1][0], dp[i][0]);
    for(_ i = n; i >= 1; --i) dp[i][1] = max(dp[i+1][1], dp[i][1]) + a[i];
    for(_ i = n; i >= 1; --i) {
        b[i][1] = max(b[i+1][1], dp[i][1]);
        s = max(s, max(b[i-1][0]+b[i][1], b[i][0]+b[i+1][1]));
    }
    
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}
