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

constant maxn = 1E3+8;
struct interval {
    _ a, b;
    bool operator < (const interval &b) const {
        return a > b.a;
    }
} a[maxn], b[maxn];

_ n, m;
priority_queue<interval> q;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) scanf(_llin, &a[i].a, &a[i].b);
    scanf(_lin, &m);
    for(_ i = 1; i <= m; ++i) scanf(_llin, &b[i].a, &b[i].b);
    for(_ i = 1; i <= n; ++i)
        for(_ j = 1; j <= m; ++j)
            if(max(a[i].a, b[j].a) <= min(a[i].b, b[j].b))
                q.push({max(a[i].a, b[j].a), min(a[i].b, b[j].b)});
    
    printf(fs(_l+"\n"), q.size());
    for(; !q.empty(); q.pop()) printf(fs(_l+" "+_l+"\n"), q.top().a, q.top().b);
    
    return 0;
}
