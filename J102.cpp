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

constant maxn = 1E5+8;

struct road {
    _ s, e;
} a[maxn];

_ sy, x, n, st, e, y, s, c;

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &sy, &x, &n);
    for(_ i = 1; i <= n; ++i, ++c) {
        scanf(_lllin, &y, &st, &e);
        if(y > sy) break;
        a[i] = {st, e};
    }
    reverse(a+1, a+1+c);
    for(_ i = 1; i <= n; ++i) if((a[i].s <= x && a[i].e >= x) || (a[i].s >= x && a[i].e <= x)) {
        ++s;
        x = a[i].e;
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}
