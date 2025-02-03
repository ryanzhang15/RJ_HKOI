
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
#include <thread>
#include <chrono>

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



constant maxa = 10+8;
_ n, cnt;
char a[maxa][5], d1[] = {'C', 'T', 'S'}, d2[] = {'B', 'R', 'Y'}, d3[] = {'W', 'G', 'B'};
bool v[100][100][100];

inline void recur(_ x, _ c);
void AC() {
    
    n = read();
    a[1][1] = getUp();
    a[1][2] = getUp();
    a[1][3] = getUp();
    v[a[1][1]][a[1][2]][a[1][3]] = true;
    recur(2, 0);
    writeln(-1);
    
    return;
}

inline void recur(_ x, _ c) {
    if(++cnt > 5E6) {
        writeln(-1);
        leave;
    }
    if(x > 9) {
        if(c != n) return;
        for(_ i = 1; i <= 9; ++i) {
            writesc(a[i]+1);
            if(!(i%3)) clr();
        }
        leave
    }
    for(_ i = 0; i < 3; ++i) for(_ j = 0; j < 3; ++j) for(_ k = 0; k < 3; ++k) if(!v[d1[i]][d2[j]][d3[k]]) {
        _ t = 0;
        for(_ f = 1; f < x; ++f) for(_ g = f+1; g < x; ++g) t += ((a[f][1] != a[g][1] && a[g][1] != d1[i] && a[f][1] != d1[i]) || (a[f][1] == a[g][1] && a[g][1] == d1[i] && a[f][1] == d1[i])) && ((a[f][2] != a[g][2] && a[g][2] != d2[j] && a[f][2] != d2[j]) || (a[f][2] == a[g][2] && a[g][2] == d2[j] && a[f][2] == d2[j])) && ((a[f][3] != a[g][3] && a[g][3] != d3[k] && a[f][3] != d3[k]) || (a[f][3] == a[g][3] && a[g][3] == d3[k] && a[f][3] == d3[k]));
        if(c+t <= n) {
            a[x][1] = d1[i];
            a[x][2] = d2[j];
            a[x][3] = d3[k];
            v[a[x][1]][a[x][2]][a[x][3]] = true;
            recur(x+1, c+t);
            v[a[x][1]][a[x][2]][a[x][3]] = false;
        }
    }
    
    return;
}
