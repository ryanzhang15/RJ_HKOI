#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
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
typedef int _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

struct res {
    bool hasp, hass;
    _ pv1, pv2, pv3, pv4, sv;
};

unordered_map<u_, res> x;
_ n, m;
u_ a[2501];
char c;

inline int read();
int main(int argc, char * argv[]) {
    
    n = read(); m = read();
    for(register _ i = 1; i <= n; ++i) {
        if(i != 1) getchar_unlocked();
        for(register _ j = 0; j < m; ++j) {
            c = getchar_unlocked();
            if(c == '1') a[i] |= (1LL<<j);
        }
        if(!a[i]) {
            printf("1\n%d\n", i);
            exit(0);
        }
        x.insert({a[i], {false, true, -1, -1, -1, -1, i}});
    }
    for(register _ i = 1; i <= n; ++i) {
        for(register _ j = i+1; j <= n; ++j) {
            if(!(a[i] ^ a[j])) {
                printf("2\n%d %d\n", i, j);
                exit(0);
            }
            u_ t = a[i] ^ a[j];
            if(x.count(t)) {
                if(x[t].hass && i != x[t].sv && j != x[t].sv) {
                    printf("3\n%d %d %d\n", i, j, x[t].sv);
                    exit(0);
                }
                if(x[t].hasp && j != x[t].pv2) {
                    printf("4\n%d %d %d %d\n", i, j, x[t].pv1, x[t].pv2);
                    exit(0);
                }
                if(x[t].hasp && j != x[t].pv4 && x[t].pv4 != -1) {
                    printf("4\n%d %d %d %d\n", i, j, x[t].pv3, x[t].pv4);
                    exit(0);
                }
            }
        }
        for(register _ j = i+1; j <= n; ++j) {
            u_ t = a[i] ^ a[j];
            if(x.count(t)) {
                if(x[t].hasp && x[t].pv2 != j) {
                    x[t].pv3 = i;
                    x[t].pv4 = j;
                } else if(!x[t].hasp) {
                    x[t].pv1 = i;
                    x[t].pv2 = j;
                    x[t].hasp = true;
                }
            } else x.insert({t, {true, false, i, j, -1, -1}});
        }
    }
    
    putchar_unlocked('-');
    putchar_unlocked('1');
    putchar_unlocked(10);
    
    return 0;
}

inline int read()
{
    int x=0,f=1;char ch=getchar_unlocked();
    while (!(ch >= '0' && ch <= '9')){if (ch=='-') f=-1;ch=getchar_unlocked();}
    while (ch >= '0' && ch <= '9'){x=x*10+ch-48;ch=getchar_unlocked();}
    return x*f;
}

