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

constant maxn = 1E4+8;

_ p[maxn], t[maxn], n, h, d;

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &h);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &p[i]);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &t[i]);
    scanf(_lin, &d);
    if(d == 1) printf(fs(_l+"\n-1\n"), t[h]);
    else {
        n = h;
        for(_ i = 1; i <= d-2; ++i) n = t[n];
        printf(fs(_l+"\n"+_l+" "+_l+" "+_l+"\n"), h, n, p[n], t[t[n]]);
    }
    
    return 0;
}
