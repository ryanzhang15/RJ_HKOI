
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxhs = 8E6+20;
constant mod1 = 7900009;
constant mod2 = 7900017;
//constant maxhs = 30;
//constant mod1 = 22;
//constant mod2 = 24;

_ n, m, s, v1[300], v2[300], s1, s2;
_p t1[maxhs], t2[maxhs];

inline void updV();
inline _ getV();
inline char gc();
int main(int argc, char * argv[]) {
    
    freopen("photocards.in", "r", stdin);
    freopen("photocards.out", "w", stdout);
    
    srand((unsigned int)time(NULL));
    scanf("%lld%lld", &n, &m);
    for(_ i = 'a', j = 1; j <= m-1; ++i, ++j) {
        _ r = rand()%1000000000-500000000;
        s1 += r;
        v1[i] = r;
        r = rand()%1000000000-500000000;
        s2 += r;
        v2[i] = r;
    }
    v1['a'+m-1] = -s1;
    v2['a'+m-1] = -s2;
    t1[0] = t2[0] = make_pair(0, 1);
    s1 = s2 = 0;
    for(_ i = 1; i <= n; ++i) {
        char th = gc();
        s1 += v1[th];
        s2 += v2[th];
        s += getV();
        updV();
    }
    printf("%lld\n", s);
    
    return 0;
}

inline char gc() {
    char ch = getchar_unlocked();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar_unlocked();
    return ch;
}

inline _ getV() {
    _ rv = 1E18, dx = (s1%mod1+mod1)%mod1;
    if(s1 == 0) rv = min(rv, t1[0].second);
    else {
        for(; dx && t1[dx].first != s1; ) {
            if(!t1[dx].first) return 0;
            ++dx;
            if(dx >= mod1) dx -= mod1;
        }
        rv = min(rv, t1[dx].second);
    }
    if(s2 == 0) return min(rv, t2[0].second);
    dx = (s2%mod2+mod2)%mod2;
    for(; dx && t2[dx].first != s2; ) {
        if(!t2[dx].first) return 0;
        ++dx;
        if(dx >= mod2) dx -= mod2;
    }
    return min(rv, t2[dx].second);
}

inline void updV() {
    _ dx = (s1%mod1+mod1)%mod1;
    if(s1 == 0) ++t1[0].second;
    else {
        for(; !dx || (t1[dx].first && t1[dx].first != s1); ) {
            ++dx;
            if(dx >= mod1) dx -= mod1;
        }
        if(!t1[dx].first) t1[dx].first = s1;
        ++t1[dx].second;
    }
    if(s2 == 0) ++t2[0].second;
    else {
        dx = (s2%mod2+mod2)%mod2;
        for(; !dx || (t2[dx].first && t2[dx].first != s2); ) {
            ++dx;
            if(dx >= mod2) dx -= mod2;
        }
        if(!t2[dx].first) t2[dx].first = s2;
        ++t2[dx].second;
    }
    return;
}
