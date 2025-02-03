
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
//#include <unordered_map>
#include <queue>
#include <list>
#include <set>
//#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxm = 6E5+8;

struct node {
    _ d, t, p;
    bool operator < (const node &b) const {
        if(d != b.d) return d > b.d;
        else return t > b.t;
    }
};
struct edge {
    _ v, cost;
};
vector<edge> g[maxn];
pair<_, _> d[maxn];
_ n, m, l, x, y, c, cnt;
priority_queue<node> q;
bool v[maxn];

pair<_, _> add(pair<_, _> c, _ m);
bool isLarger(pair<_, _> a, pair<_, _> b);
void addEdge(_ u, _ v, _ c);
int main(int argc, char * argv[]) {
    
    scanf(_lll, &n, &m, &l);
    for(; m--; ) {
        scanf(_lll, &x, &y, &c);
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    
    for(_ i = 1; i <= n; ++i) d[i] = {1E15, 1E15};
    q.push({0, 0, 1});
    d[1] = {0, 0};
    for(; !q.empty(); ) {
        node cur = q.top();
        q.pop();
        if(v[cur.p]) continue;
        v[cur.p] = true;
        for(edge i : g[cur.p]) if(isLarger(d[i.v], add(d[cur.p], i.cost))) {
            d[i.v] = add(d[cur.p], i.cost);
            q.push({d[i.v].first, d[i.v].second, i.v});
        }
    }
    
    for(_ i = 2; i <= n; ++i) printf(fs(_l+"\n"), d[i].first+!!d[i].second);
    
    return 0;
}

bool isLarger(pair<_, _> a, pair<_, _> b) {
    if(a.first != b.first) return a.first > b.first;
    else return a.second > b.second;
}

pair<_, _> add(pair<_, _> c, _ m) {
    if(c.second+m > l) return {c.first+1, m};
    else c.second += m;
    return c;
}
