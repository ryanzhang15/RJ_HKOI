
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

struct hpa {
    str data = "";
    bool neg = false;
    hpa(_ x = 0) {
        if(x == 0) {
            neg = false;
            data.clear();
        } ef(x < 0) {
            neg = true;
            data = to_string(x*-1);
        } else {
            neg = false;
            data = to_string(x);
        }
        reverse(data.begin(), data.end());
    }
    inline void clear() {
        data = "";
        neg = false;
        return;
    }
    inline void read() {
        clear();
        char ch = getchar();
        for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') neg = true;
        for(; ch >= '0' && ch <= '9'; ch = getchar()) data.push_back(ch);
        reverse(data.begin(), data.end());
        for(; data.back() == '0'; ) data.pop_back();
        return;
    }
    inline void write(char b = '\0') {
        if(data.empty()) putchar('0');
        else {
            if(neg) putchar('-');
            for(_ i = data.length()-1; i >= 0; --i) putchar(data[i]);
        }
        if(b) putchar(b);
        return;
    }
    inline _ to_ll(_ md = 9223372036854775807) {
        _ x = 0;
        for(_ i = data.length()-1; i >= 0; --i) x = ((x<<3)+(x<<1)+(data[i]^48))%md;
        return neg ? x*-1 : x;
    }
    inline _ len() {
        if(data.empty()) return 1;
        return data.length();
    }
};
inline hpa operator + (hpa aa, hpa ba);
inline hpa operator - (hpa a, hpa b);
inline bool operator == (const hpa &a, const hpa &b) {
    return a.data == b.data && a.neg == b.neg;
}
inline bool operator != (const hpa &a, const hpa &b) {
    return !(a == b);
}
inline bool operator < (const hpa &a, const hpa &b) {
    if(a.neg != b.neg) return a.neg;
    if(a.data.length() != b.data.length()) return a.data.length() < b.data.length();
    for(_ i = a.data.length()-1; i >= 0; --i) if(a.data[i] != b.data[i]) return a.data[i] < b.data[i];
    return false;
}
inline bool operator > (const hpa &a, const hpa &b) {
    return !(a < b) && !(a == b);
}
inline bool operator <= (const hpa &a, const hpa &b) {
    return a < b || a == b;
}
inline bool operator >= (const hpa &a, const hpa &b) {
    return !(a < b);
}
inline hpa operator + (hpa aa, hpa ba) {
    if(aa.neg && !ba.neg) {
        aa.neg = false;
        return ba-aa;
    }
    if(!aa.neg && ba.neg) {
        ba.neg = false;
        return aa-ba;
    }
    hpa rv;
    rv.neg = aa.neg;
    str &a = aa.data, &b = ba.data;
    if(a.length() > b.length()) swap(a, b);
    _ cr = 0, al = a.length(), bl = b.length();
    for(_ i = 0; i < al; ++i) {
        _ t = (a[i]^48)+(b[i]^48)+cr;
        rv.data.push_back((t%10)^48);
        cr = t/10;
    }
    for(_ i = al; i < bl; ++i) {
        _ t = (b[i]^48)+cr;
        rv.data.push_back((t%10)^48);
        cr = t/10;
    }
    if(cr) rv.data.push_back(cr^48);
    return rv;
}
inline hpa operator - (hpa aa, hpa ba) {
    if(aa == ba) return hpa();
    if(aa.neg && !ba.neg) {
        aa.neg = false;
        hpa rv = aa+ba;
        rv.neg = true;
        return rv;
    }
    if(!aa.neg && ba.neg) {
        ba.neg = false;
        return aa+ba;
    }
    if(aa.neg) {
        aa.neg = false;
        ba.neg = false;
        return ba-aa;
    }
    hpa rv;
    str &a = aa.data, &b = ba.data;
    bool lg = false;
    if(a.length() == b.length()) for(_ i = b.length(); i >= 0; --i) if(a[i] != b[i]) {
        lg = a[i] < b[i];
        break;
    }
    if(a.length() < b.length() || lg) {
        rv.neg = true;
        swap(a, b);
    }
    _ al = a.length(), bl = b.length();
    bool tk = false;
    for(_ i = 0; i < al; ++i) {
        _ x = a[i]^48, y;
        if(i >= bl) y = 0;
        else y = b[i]^48;
        if(tk) --x;
        if(x < y) {
            tk = true;
            x += 10;
        } else tk = false;
        rv.data.push_back((x-y)^48);
    }
    for(; !rv.data.empty() && !(rv.data.back()^48); ) rv.data.pop_back();
    return rv;
}
inline hpa operator * (hpa aa, hpa ba) {
    if(aa.data.empty() || ba.data.empty()) return hpa();
    hpa rv;
    rv.neg = aa.neg ^ ba.neg;
    str &a = aa.data, &b = ba.data;
    if(a.length() < b.length()) swap(a, b);
    _ al = a.length(), bl = b.length();
    vector<int> c (al+bl, 0);
    for(_ i = 0; i < al; ++i) for(_ j = 0; j < bl; ++j) c[i+j] += (a[i]^not 48)*(b[j]^48);
    for(_ i = 0; i < al+bl; ++i) if(c[i] >= 10) {
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }
    for(_ i = 0; i < al+bl; ++i) rv.data.push_back(c[i]^48);
    for(; !(rv.data.back()^48); ) rv.data.pop_back();
    return rv;
}
inline hpa operator / (hpa aa, _ b) {
    if(aa.data.empty()) return hpa();
    hpa rv;
    rv.neg = aa.neg ^ (b < 0);
    if(b < 0) b *= -1;
    str &a = aa.data;
    _ cr = 0, al = a.length();
    bool ok = false;
    for(_ i = 0; i < al; ++i) {
        cr = (cr<<3)+(cr<<1)+(a[al-i-1]^48);
        _ d = cr/b;
        if(d) ok = true;
        if(ok) rv.data.push_back(d^48);
        cr %= b;
    }
    reverse(rv.data.begin(), rv.data.end());
    return rv;
}
inline hpa operator % (hpa aa, _ b) {
    if(aa.data.empty()) return hpa();
    hpa rv;
    rv.neg = aa.neg;
    if(b < 0) b *= -1;
    str &a = aa.data;
    _ cr = 0;
    for(_ i = a.length()-1; i >= 0; --i) cr = ((cr<<3)+(cr<<1)+(a[i]^48))%b;
    rv.data = to_string(cr);
    reverse(rv.data.begin(), rv.data.end());
    return rv;
}
inline void operator += (hpa &a, const hpa &b) {
    a = a+b;
}
inline void operator -= (hpa &a, const hpa &b) {
    a = a-b;
}
inline void operator *= (hpa &a, const hpa &b) {
    a = a*b;
}
inline void operator /= (hpa &a, const _ &b) {
    a = a/b;
}
inline void operator %= (hpa &a, const _ &b) {
    a = a%b;
}

// ----- End of Template -----



constant maxn = 1E6+8;

str a, b, da, db;
char c;
_ p[maxn], pb[maxn], d[maxn];
v_ g, ga, gb;

_ mrg(_ x, _ y);
_ cmp(char x, char y);
inline void AC() {
    
    read(a);
    read(b);
    c = getDg();
    if(a.length() > b.length()+1) {
        bool ok = false;
        for(char i : b) {
            if(!ok && c > i) {
                write(c);
                ok = true;
            }
            write(i);
        }
        if(!ok) write(c);
        clr();
    } ef(a.length() < b.length()+1) {
        bool ok = false;
        for(char i : b) {
            if(!ok && c < i) {
                write(c);
                ok = true;
            }
            write(i);
        }
        if(!ok) write(c);
        clr();
    } else {
        p[0] = 2;
        _ n = b.length();
        a = " "+a;
        b = " "+b;
        for(_ i = 1; i <= n; ++i) p[i] = mrg(p[i-1], cmp(b[i], a[i]));
        pb[n+1] = 2;
        for(_ i = n; i >= 1; --i) pb[i] = mrg(cmp(b[i], a[i+1]), pb[i+1]);
        d[n] = n;
        for(_ i = n-1; i >= 1; --i) {
            if(cmp(b[i], b[i+1])) d[i] = i;
            else d[i] = d[i+1];
        }
        for(_ i = 0; i <= n; ++i) {
            _ x = p[i];
            x = mrg(x, cmp(c, a[i+1]));
            x = mrg(x, pb[i+1]);
            if(x == 0) g.push_back(i);
            ef(x == -1) ga.push_back(i);
            else gb.push_back(i);
        }
        if(g.empty()) {
            if(ga.empty() && gb.empty()) exit(1);
            _ ca = ga.empty() ? -1 : ga.front(), cb = gb.empty() ? -1 : gb.front();
            if(!ga.empty()) for(_ i = 1; i < ga.size(); ++i) {
                _ x = cmp(c, b[ca+1]);
                if(d[ca+1] <= ga[i]) x = mrg(x, cmp(b[d[ca+1]], b[d[ca+1]+1]));
                x = mrg(x, cmp(b[ga[i]], c));
                if(x == -1) ca = ga[i];
            }
            if(!gb.empty()) for(_ i = 1; i < gb.size(); ++i) {
                _ x = cmp(c, b[cb+1]);
                if(d[cb+1] <= gb[i]) x = mrg(x, cmp(b[d[cb+1]], b[d[cb+1]+1]));
                x = mrg(x, b[gb[i]]);
                if(x == 1) cb = gb[i];
            }
            if(~ca) {
                for(_ i = 1; i <= ca; ++i) da.push_back(b[i]);
                da.push_back(c);
                for(_ i = ca+1; i <= n; ++i) da.push_back(b[i]);
            }
            if(~cb) {
                for(_ i = 1; i <= cb; ++i) db.push_back(b[i]);
                db.push_back(c);
                for(_ i = cb+1; i <= n; ++i) db.push_back(b[i]);
            }
        } else {
            for(_ i = 1; i <= g.front(); ++i) da.push_back(b[i]);
            da.push_back(c);
            for(_ i = g.front()+1; i <= n; ++i) da.push_back(b[i]);
        }
        if(da.empty() && db.empty()) exit(1);
        if(da.empty()) writeln(db);
        ef(db.empty()) writeln(da);
        else {
            hpa ca, cb, cx;
            ca.data = da;
            cb.data = db;
            cx.data = a.substr(1);
            reverse(ca.data.begin(), ca.data.end());
            reverse(cb.data.begin(), cb.data.end());
            reverse(cx.data.begin(), cx.data.end());
            ca = cx-ca;
            cb -= cx;
            if(ca < cb) writeln(da);
            else writeln(db);
        }
    }
   
    return;
}

_ cmp(char x, char y) {
    if(x == y) return 0;
    if(x > y) return 1;
    return -1;
}

_ mrg(_ x, _ y) {
    if(x == 2) return y;
    if(y == 2) return x;
    if(x) return x;
    return y;
}
