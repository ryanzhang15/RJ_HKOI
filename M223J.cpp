
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <bitset>
#include <string>
#include <stack>
#include <unordered_set>
#include <vector>
#include <map>

#define ef else if
#define mp(x, y) make_pair(x, y)
#define pr(x, y) pair< x, y >

using namespace std;

typedef long long _;
typedef long long ll;
typedef int _0;
typedef double _D;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

inline _ read() {
    _ x = 0, d = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') d *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*d;
}

inline void read(str & a) {
    a.clear();
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ) ch = getchar();
    for(; !(ch == ' ' || ch == '\n' || ch == EOF); ch = getchar()) a += ch;
    return;
}

inline void read(char * a) {
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ) ch = getchar();
    for(; !(ch == ' ' || ch == '\n' || ch == EOF); ch = getchar()) {
        *a = ch;
        ++a;
    }
    *a = '\0';
    return;
}

constant maxn = 4E5+8;
constant maxlg = 30+8;

_ n, m, x, y, low[maxn], dfn[maxn], cnum, cnt, a[maxn], lg[maxn], f[maxlg][maxn], dp[maxlg][maxn], lg2[maxn], ht[maxn];
v_ g[maxn], h[maxn], c[maxn];
stack<_> st;
bitset<maxn> v;
set<_> ct;
queue<_> q;

_ lca(_ x, _ y);
void bfs();
void paint(_ x);
void tarjan(_ x, _ fa);
int main() {
    
    n = read();
    m = read();
    cnum = n;
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(; m--; ) {
        x = read();
        y = read();
        h[x].push_back(y);
        h[y].push_back(x);
    }
    tarjan(1, -1);
    for(_ i : ct) for(_ j : c[i]) {
        g[i].push_back(j);
        g[j].push_back(i);
    }
    for(_ i = 2; i <= cnum; ++i) lg2[i] = lg2[i>>1]+1;
    bfs();
    m = read();
    for(; m--; ) {
        x = read();
        y = read();
        printf("%lld\n", max(max(a[x], a[y]), lca(c[x][0], c[y][0])));
    }
    
    return 0;
}

void tarjan(_ x, _ fa) {
    _ cc = 0;
    low[x] = dfn[x] = ++cnt;
    st.push(x);
    v.set(x);
    for(_ i : h[x]) if(i != fa) {
        if(!dfn[i]) {
            ++cc;
            tarjan(i, x);
            low[x] = min(low[x], low[i]);
            if(low[i] >= dfn[x]) {
                ++cnum;
                for(; !st.empty() && st.top() != i; st.pop()) {
                    paint(st.top());
                    v.reset(st.top());
                }
                paint(st.top());
                v.reset(st.top());
                st.pop();
                paint(x);
                ct.insert(x);
            }
        } ef(v[i]) low[x] = min(low[x], dfn[i]);
    }
    if(!~fa && cc >= 2) ct.insert(x);
    return;
}

void paint(_ x) {
    c[x].push_back(cnum);
    return;
}

void bfs() {
    q.push(c[1][0]);
    for(; !q.empty(); q.pop()) for(_ i : g[q.front()]) if(i != f[0][q.front()]) {
        ht[i] = ht[q.front()]+1;
        f[0][i] = q.front();
        dp[0][i] = a[i];
        for(_ j = 1; j <= lg2[ht[i]]; ++j) {
            f[j][i] = f[j-1][f[j-1][i]];
            dp[j][i] = max(dp[j-1][i], dp[j-1][f[j-1][i]]);
        }
        q.push(i);
    }
    return;
}

_ lca(_ x, _ y) {
    if(ht[x] < ht[y]) swap(x, y);
    _ rv = -1E11;
    for(; ht[x] != ht[y]; ) {
        rv = max(rv, dp[lg2[ht[x]-ht[y]]][x]);
        x = f[lg2[ht[x]-ht[y]]][x];
    }
    if(x == y) return max(rv, a[x]);
    for(_ k = lg2[ht[x]]; k >= 0; --k) if(f[k][x] != f[k][y]) {
        rv = max(rv, dp[k][x]);
        rv = max(rv, dp[k][y]);
        x = f[k][x];
        y = f[k][y];
    }
    return max(max(dp[0][y], rv), max(dp[0][x], a[f[0][x]]));
}
