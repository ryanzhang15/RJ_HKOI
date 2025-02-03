
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

_ find(_ i, _ j);
_ n, m, i, j, as = 1E14, x, y;

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(; m--; ) {
        scanf(_llin, &x, &y);
        if(find(x, y) < as) {
            as = find(x, y);
            i = x;
            j = y;
        }
    }
    printf(fs(_l+" "+_l+"\n"), i, j);
    
    return 0;
    
}

_ find(_ i, _ j) {
    _ m = min(min(i, j), min(n-i+1, n-j+1));
    if(i<=j) return m*(4*(n-1)-4*m)+10*m-4*n-3+i+j;
    else return m*(4*n-4*m)+2*m+1-i-j;
}
