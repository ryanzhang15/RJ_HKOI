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

constant maxn = 2E3+8;
constant mod = 1000000007;
_ n, k, dp[maxn], c, a;
vector<_> g[maxn];

int main(int argc, char * argv[]) {
    
    /*
     oops forgot mod
     */
    scanf(_llin, &n, &k);
    for(_ i = 1; i <= n; ++i) dp[i] = 1;
    for(_ i = 1; i <= n; ++i) {
        for(_ j = 1; j < sqrt(i); ++j) if(!(i % j)) {
            g[i].push_back(j);
            g[i].push_back(i/j);
        }
        if(!(i % (_)ceil(sqrt(i))) && ceil(sqrt(i)) == sqrt(i)) g[i].push_back((_)sqrt(i));
    }
    for(; --k; ) for(_ i = n; i >= 1; --i) {
        c = 0;
        for(_ j : g[i]) c = (c + dp[j])%mod;
        dp[i] = c;
    }
    
    c = 0;
    for(_ i = 1; i <= n; ++i) c = (c + dp[i])%mod;
    
    printf(fs(_l+"\n"), c);
    
    return 0;
}

