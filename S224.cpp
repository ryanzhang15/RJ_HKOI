
/*
 template by c8kbf
 */

// macOS doesn't have <bits/++.h> (shame)
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
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>

//dont worry bout me, i'm not high
#define ef else if
#define leave exit(0);

#define v(x) vector<x >
#define v2(x) vector<vector<x > >
#define v3(x) vector<vector<vector<x > > >

#define q(x) queue<x >
#define dq(x) deque<x >
#define s(x) set<x >
#define st(x) stack<x >
#define ms(x) multiset<x >
#define m(x, y) map<x , y >
#define b(x) bitset<x >
#define l(x) list<x >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))
#define rd(a, sz) for(_ i = 1; i <= sz; ++i) a[i] = read();
#define wr(a, sz) for(_ i = 1; i <= sz; ++i) writesc(a[i]); clr();

#define i(x) x::iterator

#define pr(x, y) pair< x, y >
#define mp(x, y) make_pair(x, y)

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef int _0;
typedef double _D;
typedef unsigned long long u_;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x, v(char) tl = {'\n', EOF}) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return !count(tl.begin(), tl.end(), ch);
}

inline void read(char * a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) {
        *a = ch;
        ++a;
    }
    *a = '\0';
    return;
}

inline void read(str & a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    a.clear();
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) a += ch;
    return;
}

inline char getDg() {
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
    return ch;
}

inline char getLw() {
    char ch = getchar();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar();
    return ch;
}

inline char getUp() {
    char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
    return ch;
}

inline char getLtr() {
    char ch = getchar();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar();
    return ch;
}

inline char gc() {
    char ch = getchar();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar();
    return ch;
}

inline void write(_ x) {
    if(x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar((x%10)^48);
    return;
}

inline void write(_0 x) {
    write((_)x);
    return;
}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
    return;
}

inline void write(const str a) {
    write(a.c_str());
    return;
}

inline void write(char ch) {
    putchar(ch);
    return;
}

inline void write(_p a, char const * b = " ") {
    write(a.first);
    write(b);
    write(a.second);
    return;
}

inline void clr() {
    putchar(10);
    return;
}

inline void flsh(bool nl = true) {
    if(nl) clr();
    fflush(stdout);
    return;
}

inline void spc() {
    putchar(32);
    return;
}

template <class tp>
inline void writeln(tp x) {
    write(x);
    clr();
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
    clr();
    return;
}

template <class tp>
inline void writesc(tp x) {
    write(x);
    spc();
}

inline void writesc(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

template <class tp>
inline void writeflsh(tp x, bool nl = true) {
    write(x);
    flsh(nl);
}

inline void writeflsh(_p a, char const * b = " ", bool nl = true) {
    write(a, b);
    flsh(nl);
    return;
}

inline void yes(_ a = 1) {
    write(a & 1 ? 'Y' : 'y');
    write(a & 2 ? 'E' : 'e');
    write(a & 4 ? 'S' : 's');
    clr();
    return;
}

inline void no(_ a = 1) {
    write(a & 1 ? 'N' : 'n');
    write(a & 2 ? 'O' : 'o');
    clr();
    return;
}

//loop systems
inline v_ rg(_ r, _ l = 1, _ d = 1) {
    v_ rv;
    for(_ i = l; i <= r; i += d) rv.push_back(i);
    return rv;
}

inline v_ dg(_ r, _ l = 1, _ d = -1) {
    v_ rv;
    for(_ i = r; i >= l; i += d) rv.push_back(i);
    return rv;
}

inline void AC();
int main(int argc, char * argv[]) {

//    #define file_IO
#ifdef file_IO
    str fileN = "";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

//    #define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif

    return 0;
}

// ----- End of Template -----




constant maxn = 5E2+8;

_ dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, n, m, da[maxn][maxn], db[maxn][maxn], us[maxn][maxn];
_p xa, xb, ya, yb, pa[maxn][maxn], pb[maxn][maxn];
queue<_p> q;
stack<_p> sa, sb;

void oB();
void oA();
void pthB(_p p);
void pthA(_p p);
bool fillB();
void fillA();
inline void AC() {
    
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &n, &m, &xa.first, &xa.second, &xb.first, &xb.second, &ya.first, &ya.second, &yb.first, &yb.second);
    if(n == 1 || m == 1) {
        fillA();
        pthA(xb);
        if(!fillB()) {
            puts("Impossible");
            exit(0);
        }
        pthB(yb);
        puts("Possible");
        oA();
        oB();
    } ef((xa.first != 1 && xa.first != n && xa.second != 1 && xa.second != m) || (xb.first != 1 && xb.first != n && xb.second != 1 && xb.second != m)) {
        fillA();
        pthA(xb);
        if(!fillB()) {
            puts("Impossible");
            exit(0);
        }
        pthB(yb);
        puts("Possible");
        oA();
        oB();
    } else {
        _p c = xb;
        sa.push(c);
        us[c.first][c.second] = 1;
        for(; c != xa; ) {
            if(c.first == 1 && c.second != m) ++c.second;
            ef(c.first == n && c.second != 1) --c.second;
            ef(c.second == 1 && c.first != 1) --c.first;
            else ++c.first;
            if(c.first <= 0 || c.second <= 0 || c.first > n || c.second > m) for(;;);
            sa.push(c);
            us[c.first][c.second] = 1;
        }
        if(fillB()) {
            puts("Possible");
            pthB(yb);
            oA();
            oB();
            exit(0);
        }
        for(; !sa.empty(); ) sa.pop();
        memset(us, 0, sizeof us);
        c = xb;
        sa.push(c);
        us[c.first][c.second] = 1;
        for(; c != xa; ) {
            if(c.first == 1 && c.second != 1) --c.second;
            ef(c.first == n && c.second != m) ++c.second;
            ef(c.second == 1 && c.first != n) ++c.first;
            else --c.first;
            if(c.first <= 0 || c.second <= 0 || c.first > n || c.second > m) for(;;);
            sa.push(c);
            if(sa.size() > 1E4) {
                puts("Impossible");
                exit(0);
            }
            us[c.first][c.second] = 1;
        }
        if(fillB()) {
            puts("Possible");
            pthB(yb);
            oA();
            oB();
            exit(0);
        }
        puts("Impossible");
    }
    
    return;
}

void fillA() {
    da[ya.first][ya.second] = da[yb.first][yb.second] = 1;
    for(; !q.empty(); ) q.pop();
    q.push(xa);
    da[xa.first][xa.second] = 1;
    for(; !q.empty(); q.pop()) {
        _p t = q.front();
        for(_ i = 0; i < 4; ++i) {
            _ nx = t.first+dx[i], ny = t.second+dy[i];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m || da[nx][ny]) continue;
            da[nx][ny] = 1;
            pa[nx][ny] = t;
            q.push(make_pair(nx, ny));
        }
    }
    return;
}

bool fillB() {
    if(us[ya.first][ya.second] || us[yb.first][yb.second]) return false;
    for(; !q.empty(); ) q.pop();
    memset(db, 0, sizeof db);
    q.push(ya);
    db[ya.first][ya.second] = 1;
    for(; !q.empty(); q.pop()) {
        _p t = q.front();
        for(_ i = 0; i < 4; ++i) {
            _ nx = t.first+dx[i], ny = t.second+dy[i];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m || us[nx][ny] || db[nx][ny]) continue;
            db[nx][ny] = 1;
            pb[nx][ny] = t;
            if(nx == yb.first && ny == yb.second) return true;
            q.push(make_pair(nx, ny));
        }
    }
    return false;
}

void pthA(_p p) {
    if(p.first <= 0 || p.second <= 0) {
        puts("Impossible");
        exit(0);
    }
    if(p == xa) {
        sa.push(p);
        us[p.first][p.second] = 1;
        return;
    }
    sa.push(p);
    us[p.first][p.second] = 1;
    pthA(pa[p.first][p.second]);
    return;
}

void pthB(_p p) {
    if(p.first <= 0 || p.second <= 0 || sb.size() > 1E4) {
        puts("Impossible");
        exit(0);
    }
    if(p == ya) {
        sb.push(p);
        return;
    }
    sb.push(p);
    pthB(pb[p.first][p.second]);
    return;
}

void oA() {
    printf("%lld\n", (_)sa.size());
    for(; !sa.empty(); sa.pop()) printf("%lld %lld\n", sa.top().first, sa.top().second);
    return;
}

void oB() {
    printf("%lld\n", (_)sb.size());
    for(; !sb.empty(); sb.pop()) printf("%lld %lld\n", sb.top().first, sb.top().second);
    return;
}
