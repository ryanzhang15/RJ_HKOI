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
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E6+88;

unordered_map<_, _> x;

struct diff {
    _ a, b, c;
} d[maxn];
_ n, cnt, p[maxn<<1], T, i, j, e, t;
bool flag;

_ find(_ t);
int main(int argc, char * argv[]) {
        
    scanf(_lin, &T);
    for(; T--; ) {
        x.clear();
        cnt = t = flag = 0;
        scanf(_lin, &n);
        for(i = 1; i <= 2*n; ++i) p[i] = i;
        for(; n--; ) {
            scanf(_lllin, &i, &j, &e);
            if(!x.count(i)) x[i] = ++cnt;
            if(!x.count(j)) x[j] = ++cnt;
            i = x[i];
            j = x[j];
            if(e) p[find(i)] = find(j);
            else d[++t] = {i, j};
        }
        for(_ i = 1; i <= t && !flag; ++i) if(find(d[i].a) == find(d[i].b)) flag = true;
        if(flag) puts("NO");
        else puts("YES");
    }
    
    return 0;
}

_ find(_ t) {
    return p[t] == t ? t : p[t] = find(p[t]);
}
