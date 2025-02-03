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
#include <queue>
#include <list>
#include <set>

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

constant maxn = 1E5+88;

struct node {
    _ dir;
    str job;
} a[maxn];

_ n, m, x, y, p;

int main(int argc, char * argv[]) {
    
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    
    scanf(_llin, &n, &m);
    for(_ i = 0; i < n; ++i) cin >> a[i].dir >> a[i].job;
    for(; m--; ) {
        scanf(_llin, &x, &y);
        if((!a[p].dir && !x) || (a[p].dir && x)) p = (p-y+n)%n;
        else p = (p+y)%n;
    }
    
    cout << a[p].job << endl;
    
    return 0;
}
