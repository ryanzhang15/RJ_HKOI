#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

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
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
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

constant maxn = 1E5+8;

_ t, dp[maxn], n, c, lb(_ p);

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    memset(dp, 50, sizeof(dp));
    for(; n--; ) {
        scanf(_lin, &c);
        _ a = lb(c);
        if(a == t) ++t;
        dp[a] = c;
    }
    
    printf(fs(_l+"\n"), t);
    
    return 0;
}

_ lb(_ p) {
    _ l = 0, r = t, m, a = -1;
    while(l <= r) {
        m = (l+r)/2;
        if(dp[m] >= p) {
            a = m;
            r = m - 1;
        } else l = m + 1;
    }
    return a;
}
