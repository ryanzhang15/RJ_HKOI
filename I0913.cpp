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

constant maxn = 2E3+8;
struct node {
    _ s, id, t;
    bool operator < (const node &b) const {
        if(s == b.s) {
            if(t != b.t) return t > b.t;
            return id < b.id;
        }
        return s > b.s;
    }
} b[maxn];

_ n, t, p, u[maxn], c;
bool a[maxn][maxn];

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &n, &t, &p);
    for(_ i = 1; i <= n; ++i)
        for(_ j = 1; j <= t; ++j) {
            scanf(_lin, &c);
            a[i][j] = c;
            u[j] += !c;
        }
    
    for(_ i = 1; i <= n; ++i) {
        b[i].id = i;
        for(_ j = 1; j <= t; ++j) if(a[i][j]) {
            b[i].s += u[j];
            ++b[i].t;
        }
    }
    
    sort(b+1, b+1+n);
    
    for(_ i = 1; i <= n; ++i)
        if(b[i].id == p) {
            printf(fs(_l+" "+_l+"\n"), b[i].s, i);
            exit(0);
        }
    
    return 0;
}
