#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
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

constant maxn = 5E5+88;
_ n, t, l[maxn], r[maxn];
set<_> s;
set<_, greater<_> > g;
set<_>::iterator it;
set<_, greater<_> >::iterator it2;
unordered_map<_, _> x;

inline int read();
int main(int argc, char * argv[]) {
    
    //freopen("/Users/ryan/Desktop/g.txt", "r", stdin);
    //freopen("/Users/ryan/Desktop/f.txt", "w", stdout);
    
    n = read();
    for(_ i = 1; i <= n; ++i) {
        t = read();
        x[t] = i;
        it = s.lower_bound(t);
        it2 = g.lower_bound(t);
        if(i-1) {
            if(it == s.end() || l[x[*it]]) r[x[*it2]] = t;
            else l[x[*it]] = t;
        }
        s.insert(t);
        g.insert(t);
    }
    
    for(_ i = 1; i <= n; ++i) printf("%lld %lld\n", l[i], r[i]);
    
    return 0;
}

inline int read() {
    int x=0,f=1;char ch=getchar_unlocked();
    while (!(ch >= '0' && ch <= '9')){if (ch=='-') f=-1;ch=getchar_unlocked();}
    while (ch >= '0' && ch <= '9'){x=x*10+ch-48;ch=getchar_unlocked();}
    return x*f;
}
