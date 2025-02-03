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

constant maxn = 1E6+8;
constant maxm = 2E3+8;

_ n, m, a[maxn], c[maxm], e, ans, l, r, mid, ce, x;
bool check(_ p);

int main(int argc, char * argv[]) {
    
    //looks like binary search...
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; i++) scanf(_lin, &a[i]);
    
    l = 1; r = n;
    while(l <= r) {
        mid = (l+r)/2;
        memset(c, 0, sizeof(c));
        if(check(mid)) {
            e = ce;
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }
    
    printf(fs(_l+" "+_l+"\n"), e-ans+1, e);
    
    return 0;
}

bool check(_ p) {
    x = m;
    for(_ i = 1; i <= n; i++) {
        if(++c[a[i]] == 1) x--;
        if(i > p && --c[a[i-p]] == 0) x++;
        if(!x) {
            ce = i;
            return true;
        }
    }
    return false;
}
