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

constant maxn = 16;
_ n, a[maxn+8][maxn+8], s, dp[(1<<maxn)+8];
bool col[maxn];

_ ct1s(_ x);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) scanf(_lin, &a[i][j]);
    for(_ i = 0; i < 1<<n; ++i) for(_ j = 1; j <= n; ++j) {
        if(i & (1<<(j-1))) continue;
        dp[i | (1<<(j-1))] = max(dp[i | (1<<(j-1))], dp[i]+a[ct1s(i)+1][j]);
    }
    printf(fs(_l+"\n"), *max_element(dp+1, dp+(1<<n)));
    
    return 0;
}

_ ct1s(_ x) {
    bitset<64> b (x);
    return b.count();
}
