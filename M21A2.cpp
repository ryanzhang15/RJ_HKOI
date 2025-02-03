
/*
 template by c8kbf
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



_ t, c;

void AC() {
    
    t = read();
    for(; t--; ) {
        c = read()/100;
        if(c <= 7) writeln("PR");
        ef(c == 8) writeln("VI");
        ef(c == 9) writeln("PR");
        ef(c <= 27) writeln("MA");
        ef(c <= 29) writeln("RI");
        ef(c <= 38) writeln("NH");
        ef(c <= 49) writeln("ME");
        ef(c <= 54) writeln("VT");
        ef(c == 44) writeln("MA");
        ef(c <= 59) writeln("VT");
        ef(c <= 69) writeln("CT");
        ef(c <= 89) writeln("NJ");
        ef(c <= 99) writeln("AE");
        ef(c <= 149) writeln("NY");
        ef(c <= 196) writeln("PA");
        ef(c <= 199) writeln("DE");
        ef(c == 200) writeln("DC");
        ef(c == 201) writeln("VA");
        ef(c <= 205) writeln("DC");
        ef(c <= 219) writeln("MD");
        ef(c <= 246) writeln("VA");
        ef(c <= 268) writeln("WV");
        ef(c <= 289) writeln("NC");
        ef(c <= 299) writeln("SC");
        ef(c <= 319) writeln("GA");
        ef(c <= 349) writeln("FL");
        ef(c <= 369) writeln("AL");
        ef(c <= 385) writeln("TN");
        ef(c <= 397) writeln("MS");
        ef(c <= 399) writeln("GA");
        ef(c <= 427) writeln("KY");
        ef(c <= 459) writeln("OH");
        ef(c <= 479) writeln("IN");
        ef(c <= 499) writeln("MI");
        ef(c <= 528) writeln("IA");
        ef(c <= 549) writeln("WI");
        ef(c <= 567) writeln("MN");
        ef(c <= 569) writeln("DC");
        ef(c <= 577) writeln("SD");
        ef(c <= 588) writeln("ND");
        ef(c <= 599) writeln("MT");
        ef(c <= 629) writeln("IL");
        ef(c <= 658) writeln("MO");
        ef(c <= 679) writeln("KS");
        ef(c <= 693) writeln("NE");
        ef(c <= 714) writeln("LA");
        ef(c <= 729) writeln("AR");
        ef(c <= 731) writeln("OK");
        ef(c <= 733) writeln("TX");
        ef(c <= 749) writeln("OK");
        ef(c <= 799) writeln("TX");
        ef(c <= 816) writeln("CO");
        ef(c <= 831) writeln("WY");
        ef(c <= 838) writeln("ID");
        ef(c <= 847) writeln("UT");
        ef(c <= 865) writeln("AZ");
        ef(c <= 884) writeln("NM");
        ef(c == 885) writeln("TX");
        ef(c <= 898) writeln("NV");
        ef(c <= 961) writeln("CA");
        ef(c <= 966) writeln("AP");
        ef(c <= 968) writeln("HI");
        ef(c == 969) writeln("GU");
        ef(c <= 979) writeln("OR");
        ef(c <= 994) writeln("WA");
        else writeln("AK");
    }
    
    return;
}
