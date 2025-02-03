
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <ctime>
#include <map>
#include <numeric>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef int _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

constant maxn = 1E6+8;

_ n, m, cnt, a[maxn], c[maxn], op, ln, x, y;
unordered_map<_, _> mp;
set<_> b[maxn];

inline _ dc(_ x);
int main() {
    
    n = read();
    read();
    for(_ i = 1; i <= n; ++i) {
        a[i] = read();
        b[dc(a[i])].insert(i);
    }
    m = read();
    for(; m--; ) {
        op = read();
        if(op == 1) {
            x = read();
            y = read();
            b[dc(a[x])].erase(x);
            a[x] = y;
            b[dc(a[x])].insert(x);
        } else {
            ln = read();
            for(_ i = 1; i <= ln; ++i) c[i] = read();
            bool ok = true;
            _ p = 0;
            for(_ i = 1; i <= ln; ++i) {
                if(!mp.count(c[i])) {
                    ok = false;
                    break;
                }
                _ t = dc(c[i]);
                set<_>::iterator it = b[t].upper_bound(p);
                if(it == b[t].end()) {
                    ok = false;
                    break;
                }
                p = *it;
            }
            if(ok) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}

inline _ dc(_ x) {
    if(mp.count(x)) return mp[x];
    return mp[x] = ++cnt;
}

