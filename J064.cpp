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

constant maxn = 5E2+8;
_ n, c, d;
vector<_> g[maxn];
stack<_> s;
bool u[maxn];

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(_lin, &c);
        for(; c--; ) {
            scanf(_lin, &d);
            g[i].push_back(d);
        }
    }
    
    for(_ i = n; i >= 1; --i) {
        if(u[i]) continue;
        for(_ j : g[i]) {
            if(u[j]) {
                puts("-1");
                exit(0);
            }
            u[j] = true;
        }
        s.push(i);
    }
    
    for(; !s.empty(); s.pop()) printf(fs(_l+"\n"), s.top());
    
    return 0;
}
