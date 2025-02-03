
/*
 the c8kbf template
 */

// macOS doesn't have <bits/stdc++.h> (shame)
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

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef unsigned long long u_;
typedef long double _D;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

char untl = '\n';

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x) {
    x = 0;
    _ f = 1;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar_unlocked();
    return ch != untl && ch != EOF;
}

inline char getDg() {
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    return ch;
}

inline char getLw() {
    char ch = getchar_unlocked();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar_unlocked();
    return ch;
}

inline char getUp() {
    char ch = getchar_unlocked();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar_unlocked();
    return ch;
}

inline char getLtr() {
    char ch = getchar_unlocked();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar_unlocked();
    return ch;
}

inline char gc() {
    char ch = getchar_unlocked();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar_unlocked();
    return ch;
}

inline void write(_ x) {
    if(x < 0) {
        putchar_unlocked('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar_unlocked((x%10)^48);
    return;
}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar_unlocked(a[i]);
    return;
}

inline void clr() {
    putchar_unlocked(10);
    return;
}

inline void spc() {
    putchar_unlocked(32);
    return;
}

inline void writeln(_ x) { //pascal vibes
    write(x);
    clr();
    return;
}

inline void writeln(char const * a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writesc(_ x) {
    write(x);
    spc();
    return;
}

inline void writesc(char const * a) {
    write(a);
    spc();
    return;
}

void AC();
int main(int argc, char * argv[]) {
    
    str fileN = "";
    
    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    AC(); // good luck!
    
    return 0;
}



// ----- End of Template -----



constant maxd = 10+8;

str hand, t, st[] = {"111", "222", "333", "444", "555", "666", "777", "888", "999", "123", "234", "345", "456", "567", "678", "789"}, pr[] = {"11", "22", "33", "44", "55", "66", "77", "88", "99"};
_ a[maxd], s = -1E18, dx;
vector<_> c, o;
set<str> h;

_ countWin(str hand);
void AC() {
    
    // generate all successful hands
    for(_ i = 0; i < 16; ++i) for(_ j = 0; j < 16; ++j) for(_ k = 0; k < 16; ++k) for(_ m = 0; m < 16; ++m) for(_ l = 0; l < 9; ++l) {
        t = st[i] + st[j] + st[k] + st[m] + pr[l];
        sort(t.begin(), t.end());
        h.insert(t);
    }
    
    for(_ i = 1; i <= 9; ++i) a[i] = 12;
    cin >> hand;
    for(char i : hand) --a[i-'0'];
    getchar();
    for(char i = getchar(); i != '\n'; i = getchar()) --a[i-'0'];
    for(_ i = '1'; i <= '9'; ++i) {
        t = hand;
        if(t.find(i) == str::npos) continue;
        t.erase(find(t.begin(), t.end(), i));
        _ cr = countWin(t);
        if(cr > s) {
            s = cr;
            dx = i-'0';
            o = c;
        }
        c.clear();
    }
    writeln(dx);
    for(_ i : o) write(i);
    clr();
    
    return;
}

_ countWin(str hand) {
    _ rv = 0;
    for(_ i = '1'; i <= '9'; ++i) if(a[i-'0']) {
        t = hand;
        t += i;
        sort(t.begin(), t.end());
        if(h.count(t)) {
            rv += a[i-'0'];
            c.push_back(i-'0');
        }
    }
    return rv;
}

