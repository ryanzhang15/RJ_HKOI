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
//constant maxn = 20;
struct edge {
    _ v, w;
    bool operator < (const edge &b) const {
        return w > b.w;
    }
};

_ n, m, t, d[maxn], s;
vector<edge> g[maxn];
priority_queue<edge> q;
bool vis[maxn];

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    memset(d, 50, sizeof(d));
    for(; m--; ) {
        _ a, b, c;
        scanf(_lllin, &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    d[1] = 0;
    q.push({1, 0});
    while(t < n) {
        edge e = q.top();
        q.pop();
        if(vis[e.v]) continue;
        vis[e.v] = true;
        ++t;
        s += e.w;
        for(edge c : g[e.v])
            if(c.w < d[c.v]) {
                d[c.v] = c.w;
                q.push(c);
            }
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}

