
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
#define l "%lld"
#define ll "%lld%lld"
#define lll "%lld%lld%lld"
#define llll "%lld%lld%lld%lld"
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+88;

_ n, p[maxn], c, rt, lt, s, t;

int main(int argc, char * argv[]) {
    
    scanf(l, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(l, &c);
        p[c] = i;
    }
    lt = 0;
    rt = p[n]*3;
    t = 1;
    for(_ i = n; i >= 1; --i, ++s) if(t == lt+1) {
        s += rt-t-1;
        t = rt-1;
        if(p[i-1]*3 < t) lt = max(lt, p[i-1]*3);
    } else {
        if(!lt) {
            s += t;
            puts("ESCAPE");
            printf(fs(_l+"\n"+_l+"\n"), i, s);
            exit(0);
        }
        s += t-lt-1;
        t = lt+1;
        if(p[i-1]*3 > t) rt = min(rt, p[i-1]*3);
    }
    
    puts("DROP");
    printf(fs(_l+"\n"+_l+"\n"), t, s);
    
    return 0;
}
