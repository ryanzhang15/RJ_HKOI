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

constant maxn = 1E5+88;
//constant maxn = 8;

_ n, m, q, a, b, c, p[maxn], findp(_ x, _ cnt);
bool vis[maxn];

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(; m--; ) {
        scanf(_llin, &a, &b);
        p[a] = b;
    }
    
    scanf(_lin, &q);
    for(; q--; memset(vis, 0, sizeof(vis))) {
        scanf(_lin, &c);
        m = p[c] == -1 ? -1 : findp(c, 1);
        //m = findp(c, 1);
        if(m == -1) printf("Error\n");
        else printf(fs(_l+"\n"), m);
    }
    
    return 0;
}

_ findp(_ x, _ cnt) {
    if(!p[x]) return x;
    if(vis[x] || p[x] == -1) return -1;
    vis[x] = true;
    return p[x] = findp(p[x], cnt+1);
}
 
