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

constant maxn = 1E5+8;

_ n, m, a, b, dfn[maxn], low[maxn], c[maxn], cnum, cnt, in[maxn], z;
vector<_> g[maxn], G[maxn];
stack<_> s;
queue<_> q;
bool vis[maxn], flag;

void paint(_ x);
void tarjan(_ x);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &z);
    for(; z--; ) {
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(c, 0, sizeof c);
        memset(in, 0, sizeof in);
        memset(vis, 0, sizeof vis);
        for(; !s.empty(); ) s.pop();
        for(; !q.empty(); ) q.pop();
        n = m = a = b = cnum = cnt = flag = 0; //just in case idk
        for(_ i = 1; i <= maxn-1; ++i) {
            g[i].clear();
            G[i].clear();
        }
        scanf(_llin, &n, &m);
        for(; m--; ) {
            scanf(_llin, &a, &b);
            g[a].push_back(b);
        }
        for(_ i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
        for(_ i = 1; i <= n; ++i) for(_ j : g[i]) if(c[i] != c[j]) {
            G[c[i]].push_back(c[j]);
            ++in[c[j]];
        }
        for(_ i = 1; i <= cnum; ++i) if(!in[i]) q.push(i);
        flag = true;
        for(; !q.empty(); q.pop()) {
            if(q.size() >= 2) {
                flag = false;
                break;
            }
            for(_ i : G[q.front()]) if(!--in[i]) q.push(i);
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    
    return 0;
}

void tarjan(_ x) {
    dfn[x] = low[x] = ++cnt;
    s.push(x);
    vis[x] = true;
    for(_ i : g[x]) {
        if(!dfn[i]) {
            tarjan(i);
            low[x] = min(low[x], low[i]);
        } else if(vis[i]) low[x] = min(low[x], dfn[i]);
    }
    if(low[x] == dfn[x]) {
        ++cnum;
        for(; !s.empty() && s.top() != x; ) paint(s.top());
        paint(x);
    }
    return;
}

void paint(_ x) {
    s.pop();
    c[x] = cnum;
    vis[x] = false;
    return;
}

/*
 2
 3 3
 1 2
 2 3
 3 1
 3 3
 1 2
 2 3
 3 1
 */
