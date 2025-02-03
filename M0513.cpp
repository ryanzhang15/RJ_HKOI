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

constant maxn = 9+8;
_ dp[maxn][maxn], len;
char a[maxn];

_ dfs(_ pos, _ pre, bool limit);
int main(int argc, char * argv[]) {
    
    scanf("%s", a+1);
    len = strlen(a+1);
    for(_ i = 1; i <= len; ++i) a[i] -= '0';
    memset(dp, -1, sizeof dp);
    printf(fs(_l+"\n"), dfs(1, 0, true)-1);
    
    return 0;
}

_ dfs(_ pos, _ pre, bool limit) {
    if(pos > len && !pre) return 1;
    else if(pos > len) return 0;
    if(!limit && ~dp[pos][pre]) return dp[pos][pre];
    _ rv = 0, rs = limit ? a[pos] : 9;
    for(_ i = 0; i <= rs; ++i) rv += dfs(pos+1, (pre+i)%7, limit && i == rs);
    return !limit ? dp[pos][pre] = rv : rv;
}
