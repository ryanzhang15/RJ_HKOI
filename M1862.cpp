
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
_ n, s[maxn], t, a;
vector<_> g[maxn];
bitset<maxn> v;

void dfs(_ x);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(_lin, &t);
        g[t].push_back(i);
        if(t) g[i].push_back(t);
    }
    for(_ i = 1; i <= n; ++i) scanf(_lin, &s[i]);
    for(_ i = 1; i <= n; ++i) if(!v[i]) dfs(i);
    printf(fs(_l+"\n"), a);
    
    return 0;
}

void dfs(_ x) {
    v.flip(x);
    for(_ i : g[x]) if(!v[i]) {
        dfs(i);
        s[x] = max((_)0, s[x]-s[i]);
    }
    a += s[x];
    return;
}
