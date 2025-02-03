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

#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

struct card {
    char v, s;
    _ n;
    bool operator < (const card &b) const {
        return n < b.n;
    }
} hand[5];

_0 s;

int main(int argc, char * argv[]) {
    
    for(_ i = 0; i < 5; ++i) {
        hand[i].v = getchar();
        hand[i].s = getchar();
        getchar();
        if(hand[i].v >= '1' && hand[i].v <= '9') hand[i].n = hand[i].v - '0';
        else if(hand[i].v == 'T') hand[i].n = 10;
        else if(hand[i].v == 'J') hand[i].n = 11;
        else if(hand[i].v == 'Q') hand[i].n = 12;
        else if(hand[i].v == 'K') hand[i].n = 13;
        else if(hand[i].v == 'A') hand[i].n = 1;
    }
    
    sort(hand, hand+5);
    
    _ sc = 0;
    for(_ i = 1; i < 5; ++i) if(hand[i].n == hand[i-1].n + 1) ++sc;
    if(hand[4].n == 13 && hand[0].n == 1 && hand[3].n == 12 && hand[2].n == 11 && hand[1].n == 10) ++sc;
    if(sc >= 4) s = 1;
    bool f = true;
    for(_ i = 1; i < 5; ++i) if(hand[i].s != hand[i-1].s) f = false;
    if(f) s = s ? 5 : 2;
    if((hand[0].n == hand[1].n && hand[1].n == hand[2].n && hand[3].n == hand[4].n) || (hand[0].n == hand[1].n && hand[2].n == hand[3].n && hand[3].n == hand[4].n)) s = s ? 5 : 3;
    if((hand[0].n == hand[1].n && hand[1].n == hand[2].n && hand[2].n == hand[3].n) || (hand[1].n == hand[2].n && hand[2].n == hand[3].n && hand[3].n == hand[4].n)) s = s ? 5 : 4;
    
    putchar(s + '0');
    putchar(10);
    
    return 0;
}

