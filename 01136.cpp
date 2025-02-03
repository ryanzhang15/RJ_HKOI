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

constant maxn = 1E5+8;
//constant maxn = 6;
struct range {
    _ s, e;
    bool operator < (const range &b) const {
        return s < b.s;
    }
} c, a[maxn];

_ n, t = 1;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) scanf(_llin, &a[i].s, &a[i].e);
    sort(a+1, a+1+n);
    
    c = a[1];
    for(_ i = 2; i <= n; ++i) {
        if(a[i].s <= c.e) {
            c.s = a[i].s;
            c.e = min(c.e, a[i].e);
        }
        else {
            ++t;
            c = a[i];
        }
    }
    
    printf(fs(_l+"\n"), t);
    
    return 0;
}

