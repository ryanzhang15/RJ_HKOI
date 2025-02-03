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

constant maxn = 5E3+8;

_ d[maxn][maxn], n, m, dp[maxn];
v_ g[maxn];
struct prs {
    _ x, y, z;
    bool operator < (const prs &b) const {
        return x < b.x;
    }
} a[maxn];

void bfs(_ c);
int main() {
    
    memset(d, ~0, sizeof d);
    
    n = read();
    m = read();
    for(_ i = 1; i <= m; ++i) {
        a[i].x = read();
        a[i].y = read();
        a[i].z = read();
        dp[i] = -1E15;
    }
    sort(a+1, a+1+m);
    for(_ i = 1; i <= n-1; ++i) {
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[n].push_back(1);
    g[1].push_back(n);
    for(_ i = 1; i <= (n>>1); ++i) {
        g[i].push_back(i+(n>>1));
        g[i+(n>>1)].push_back(i);
    }
    for(_ i = 1; i <= n; ++i) bfs(i);
    a[0].y = 1;
    _ s = 0;
    for(_ i = 1; i <= m; ++i) for(_ j = 0; j <= i-1; ++j) if(d[a[j].y][a[i].y] <= a[i].x-a[j].x) {
        dp[i] = max(dp[i], dp[j]+a[i].z);
        s = max(s, dp[i]);
    }
    printf("%lld\n", s);
     
    return 0;
}

void bfs(_ c) {
    d[c][c] = 0;
    queue<_> q;
    q.push(c);
    for(; !q.empty(); q.pop()) {
        _ t = q.front();
        for(_ i : g[t]) if(!~d[c][i]) {
            d[c][i] = d[c][t]+1;
            q.push(i);
        }
    }
    return;
}
