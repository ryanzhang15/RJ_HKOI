//
///*
// template by c8kbf
// */
//
//// macOS doesn't have <bits/++.h> (shame)
//#include <cstdlib>
//
//#include <iostream>
//#include <cstdio>
//#include <iomanip>
//#include <fstream>
//
//#include <cmath>
//#include <cstring>
//#include <ctime>
//
//#include <deque>
//#include <string>
//#include <stack>
//#include <vector>
//#include <map>
//#include <queue>
//#include <list>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <bitset>
//
//#include <algorithm>
//#include <numeric>
//#include <random>
//
////dont worry bout me, i'm not high
//#define ef else if
//#define leave exit(0);
//
//#define v(x) vector<x >
//#define v2(x) vector<vector<x > >
//#define v3(x) vector<vector<vector<x > > >
//
//#define q(x) queue<x >
//#define dq(x) deque<x >
//#define s(x) set<x >
//#define st(x) stack<x >
//#define ms(x) multiset<x >
//#define m(x, y) map<x , y >
//#define b(x) bitset<x >
//#define l(x) list<x >
//
//#define ss(x) v(_)(x+8, 0)
//#define ssz(type, x) v(type)(x+8, 0)
//#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
//#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
//#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
//#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))
//#define rd(a, sz) for(_ i = 1; i <= sz; ++i) a[i] = read();
//#define wr(a, sz) for(_ i = 1; i <= sz; ++i) writesc(a[i]); clr();
//
//#define i(x) x::iterator
//
//#define pr(x, y) pair< x, y >
//#define mp(x, y) make_pair(x, y)
//
//using namespace std;
//
////weirdest typedefs ever??
//typedef long long _;
//typedef int _0;
//typedef long double _D;
//typedef unsigned long long u_;
//typedef string str;
//typedef vector<_> v_;
//typedef pair<_, _> _p;
//typedef const long long constant;
//
////fastIO cos why not
//inline _ read() {
//    _ x = 0, f = 1;
//    char ch = getchar();
//    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
//    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
//    return x*f;
//}
//
//inline bool read(_ &x, v(char) tl = {'\n', EOF}) {
//    x = 0;
//    _ f = 1;
//    char ch = getchar();
//    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
//    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
//    x *= f;
//    if(ch == '\r') ch = getchar();
//    return !count(tl.begin(), tl.end(), ch);
//}
//
//inline void read(char * a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
//    char ch = getchar();
//    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
//    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) {
//        *a = ch;
//        ++a;
//    }
//    *a = '\0';
//    return;
//}
//
//inline void read(str & a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
//    a.clear();
//    char ch = getchar();
//    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
//    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) a += ch;
//    return;
//}
//
//inline char getDg() {
//    char ch = getchar();
//    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
//    return ch;
//}
//
//inline char getLw() {
//    char ch = getchar();
//    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar();
//    return ch;
//}
//
//inline char getUp() {
//    char ch = getchar();
//    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
//    return ch;
//}
//
//inline char getLtr() {
//    char ch = getchar();
//    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar();
//    return ch;
//}
//
//inline char gc() {
//    char ch = getchar();
//    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar();
//    return ch;
//}
//
//inline void write(_ x) {
//    if(x < 0) {
//        putchar('-');
//        write(-x);
//        return;
//    }
//    if(x > 9) write(x/10);
//    putchar((x%10)^48);
//    return;
//}
//
//inline void write(_0 x) {
//    write((_)x);
//    return;
//}
//
//inline void write(char const * a) {
//    for(_ i = 0; a[i]; ++i) putchar(a[i]);
//    return;
//}
//
//inline void write(const str a) {
//    write(a.c_str());
//    return;
//}
//
//inline void write(char ch) {
//    putchar(ch);
//    return;
//}
//
//inline void write(_p a, char const * b = " ") {
//    write(a.first);
//    write(b);
//    write(a.second);
//    return;
//}
//
//inline void clr() {
//    putchar(10);
//    return;
//}
//
//inline void flsh(bool nl = true) {
//    if(nl) clr();
//    fflush(stdout);
//    return;
//}
//
//inline void spc() {
//    putchar(32);
//    return;
//}
//
//template <class tp>
//inline void writeln(tp x) {
//    write(x);
//    clr();
//}
//
//inline void writeln(_p a, char const * b = " ") {
//    write(a, b);
//    clr();
//    return;
//}
//
//template <class tp>
//inline void writesc(tp x) {
//    write(x);
//    spc();
//}
//
//inline void writesc(_p a, char const * b = " ") {
//    write(a);
//    spc();
//    return;
//}
//
//template <class tp>
//inline void writeflsh(tp x, bool nl = true) {
//    write(x);
//    flsh(nl);
//}
//
//inline void writeflsh(_p a, char const * b = " ", bool nl = true) {
//    write(a, b);
//    flsh(nl);
//    return;
//}
//
//inline void yes(_ a = 1) {
//    write(a & 1 ? 'Y' : 'y');
//    write(a & 2 ? 'E' : 'e');
//    write(a & 4 ? 'S' : 's');
//    clr();
//    return;
//}
//
//inline void no(_ a = 1) {
//    write(a & 1 ? 'N' : 'n');
//    write(a & 2 ? 'O' : 'o');
//    clr();
//    return;
//}
//
////loop systems
//inline v_ rg(_ r, _ l = 1, _ d = 1) {
//    v_ rv;
//    for(_ i = l; i <= r; i += d) rv.push_back(i);
//    return rv;
//}
//
//inline v_ dg(_ r, _ l = 1, _ d = -1) {
//    v_ rv;
//    for(_ i = r; i >= l; i += d) rv.push_back(i);
//    return rv;
//}
//
//inline void AC();
//int main(int argc, char * argv[]) {
//
////    #define file_IO
//#ifdef file_IO
//    str fileN = "";
//    freopen((fileN+".in").c_str(), "r", stdin);
//    freopen((fileN+".out").c_str(), "w", stdout);
//#endif
//
////    #define multiple_testcases
//#ifdef multiple_testcases
//    _ tc = read();
//    for(; tc--; ) AC(); // good luck!
//#else
//    AC(); // good luck!
//#endif
//
//    return 0;
//}
//
//// ----- End of Template -----
//
//
//
//
//constant maxn = 2E2+8;
//
//bool a[maxn][maxn], v[maxn][maxn];
//_ dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, c, s;
//v(_p) pa, pb;
//
//void lineB(_ x, _ y);
//void lineA(_ x, _ y);
//void dfs(_ x, _ y);
//void printGrid();
//inline void AC() {
//
//    for(_ i = 200; i >= 1; --i) pa.push_back(mp(i, 1));
//    for(_ i = 2; i <= 200; ++i) pa.push_back(mp(1, i));
//    for(_ i = 200; i >= 1; --i) pb.push_back(mp(i, 200));
//    for(_ i = 199; i >= 1; --i) pb.push_back(mp(1, i));
//
//    for(_ i = 1; i <= 200; ++i) {
//        memset(a, false, sizeof a);
//        for(_ j = 0; j < pa.size(); j += i) lineA(pa[j].first, pa[j].second);
//        lineA(pa.back().first, pa.back().second);
//        for(_ j = 0; j < pb.size(); j += i) lineB(pb[j].first, pb[j].second);
//        lineB(pb.back().first, pb.back().second);
//        s = -1E11;
//        memset(v, false, sizeof v);
//        for(_ j = 1; j <= 200; ++j) for(_ k = 1; k <= 200; ++k) if(!v[j][k]) {
//            c = 0;
//            dfs(j, k);
//            s = max(s, c);
//        }
//        if(s < 2000) {
//            c = 0;
//            for(_ j = 1; j <= 200; ++j) for(_ k = 1; k <= 200; ++k) if(a[j][k]) ++c;
//            if(s+c > 2712) continue;
//            printGrid();
//            writesc(s);
//            writeln(s+c);
//        }
//    }
//
//    return;
//}
//
//void printGrid() {
//    for(_ i = 1; i <= 200; ++i, clr()) for(_ j = 1; j <= 200; ++j) write(a[i][j] ? 'X' : '.');
//    return;
//}
//
//void dfs(_ x, _ y) {
//    if(c > 3001) return;
//    if(a[x][y]) return;
//    v[x][y] = true;
//    ++c;
//    for(_ i = 0; i < 4; ++i) {
//        _ nx = x+dx[i], ny = y+dy[i];
//        if(nx <= 0 || ny <= 0 || nx > 200 || ny > 200 || v[nx][ny]) continue;
//        dfs(nx, ny);
//    }
//    return;
//}
//
//void lineA(_ x, _ y) {
//    for(_ i = x, j = y; i <= 200 && j <= 200; ++i, ++j) a[i][j] = true;
//    return;
//}
//
//void lineB(_ x, _ y) {
//    for(_ i = x, j = y; i <= 200 && j >= 1; ++i, --j) a[i][j] = true;
//    return;
//}

#ifdef __cplusplus
extern "C" {
#endif
int search(int x, int y);
void findBug(int L);
#ifdef __cplusplus
}
#endif

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
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E2+8;

bool a[maxn][maxn];
_ sc, cnt, b[maxn][maxn];
v(_p) pa, pb;
v(pr(_, _p)) qr;

_ srch(_ x, _ y) {
    if(++sc > 40000) exit(1);
    if(x < 0 || y < 0 || x > 200 || y > 200) exit(2);
    return search(x, y);
}
void lineB(_ x, _ y);
void lineA(_ x, _ y);
//void dfs(_ x, _ y);
//void printGrid();
void findBug(int L) {
    
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    sc = cnt = 0;
    pa.clear();
    pb.clear();
    qr.clear();
    
    for(_ i = 200; i >= 1; --i) pa.push_back(mp(i, 1));
    for(_ i = 2; i <= 200; ++i) pa.push_back(mp(1, i));
    for(_ i = 200; i >= 1; --i) pb.push_back(mp(i, 200));
    for(_ i = 199; i >= 1; --i) pb.push_back(mp(1, i));
    
    for(_ j = 0; j < pa.size(); j += 45) lineA(pa[j].first, pa[j].second);
    lineA(pa.back().first, pa.back().second);
    for(_ j = 0; j < pb.size(); j += 45) lineB(pb[j].first, pb[j].second);
    lineB(pb.back().first, pb.back().second);
    
    for(_ i = 1; i <= 200; ++i) for(_ j = 1; j <= 200; ++j) if(a[i][j]) {
        b[i][j] = srch(i, j);
        if(!b[i][j]) return;
    }
    _ mx = -1E17, mn = 1E17;
    for(_ i = 1; i <= 200; ++i) for(_ j = 1; j <= 200; ++j) if(a[i][j]) {
        mx = max(mx, b[i][j]);
        mn = min(mn, b[i][j]);
    }
    if(!~L) L = mx-mn;
    for(_ i = 1; i <= 200; ++i) for(_ j = 1; j <= 200; ++j) if(a[i][j]) {
        ++cnt;
        _ sr = b[i][j];
        if(!sr) return;
        if(!~sr) continue;
        qr.push_back(mp((sr+1744-cnt)%L, mp(i, j)));
    }
    if(cnt != 1744) exit(3);
    if(qr.size() <= 1) exit(2);
//    sort(qr.begin(), qr.end());
    _ dx = -1;
    for(_ i = 0; i < qr.size(); ++i) if(!~dx || qr[i].first > qr[dx].first || qr[i].first == 0) {
        dx = i;
        if(qr[i].first == 0) break;
    }
    if(!~dx) exit(1);
    for(;;) {
        _ sr = srch(qr[dx].second.first, qr[dx].second.second);
        if(!sr) return;
    }
    
    return;
}

//void printGrid() {
//    for(_ i = 1; i <= 200; ++i, clr()) for(_ j = 1; j <= 200; ++j) write(a[i][j] ? 'X' : '.');
//    return;
//}

//void dfs(_ x, _ y) {
//    if(c > 2001) return;
//    if(a[x][y]) return;
//    v[x][y] = true;
//    ++c;
//    for(_ i = 0; i < 4; ++i) {
//        _ nx = x+dx[i], ny = y+dy[i];
//        if(nx <= 0 || ny <= 0 || nx > 200 || ny > 200 || v[nx][ny]) continue;
//        dfs(nx, ny);
//    }
//    return;
//}

void lineA(_ x, _ y) {
    for(_ i = x, j = y; i <= 200 && j <= 200; ++i, ++j) a[i][j] = true;
    return;
}

void lineB(_ x, _ y) {
    for(_ i = x, j = y; i <= 200 && j >= 1; ++i, --j) a[i][j] = true;
    return;
}

#ifndef ONLINE_JUDGE

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

_ sx, sy, pt;
str pth;

int main() {
    
    sx = read();
    sy = read();
    read(pth);
    
    
    return 0;
}

#endif
