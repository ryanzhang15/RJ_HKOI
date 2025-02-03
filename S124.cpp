#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <deque>

#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E3+8;

_ n, v, x, mn = 1E18, t[maxn];
deque<_> q;
bool trp;

inline _ read();
inline void solveQ();
inline _ query(_ x);
inline void add(_ x);
int main() {

    n = read();
    for(_ i = 1; i <= n; ++i) q.push_back(read());
    solveQ();
    for(_ i = 1; i < n; ++i) {
        for(_ &j : q) j = j == n ? 1 : j+1;
        solveQ();
    }
    printf("%lld\n", mn);
    
    return 0;
}

inline void add(_ x) {
    for(; x <= n; x += x & -x) ++t[x];
    return;
}

inline _ query(_ x) {
    _ rv = 0;
    for(; x; x -= x & -x) rv += t[x];
    return rv;
}

inline void solveQ() {
    memset(t, 0, sizeof t);
    v = 0;
    for(_ i = n-1; i >= 0; --i) {
        add(q[i]);
        v += query(q[i]-1);
    }
    mn = min(mn, v);
    for(_ i = 1; i <= n; ++i) {
        v -= q.front()-1;
        v += n-q.front();
        q.push_back(q.front());
        q.pop_front();
        mn = min(mn, v);
    }
    return;
}

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}
