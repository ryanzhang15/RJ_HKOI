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

constant maxn = 1E3+8;

_ a[maxn], n, x, y, z;

int main(int argc, char * argv []) {
    
    scanf(_lin, &n); _ N = n;
    for(; N--; ) {
        scanf(_lllin, &x, &y, &z);
        a[y] += x;
        a[z+1] -= x;
    }
    x = y = 0;
    for(_ i = 1; i <= 1000; ++i) {
        x += a[i];
        y = max(y, x);
    }
    
    printf(fs(_l+"\n"), y);
        
    return 0;
}
