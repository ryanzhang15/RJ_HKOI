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

_ dp[40][40], l, m, n, s, top;

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &l, &m, &n);
    dp[1][1] = 1;
    for(_ i = 2; i <= l; ++i) {
        top = min(i, m);
        for(_ j = (i+1)>>1; j <= top; ++j) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
    }
    
    printf(fs(_l+"\n"), dp[l][m]);
    
    return 0;
}
