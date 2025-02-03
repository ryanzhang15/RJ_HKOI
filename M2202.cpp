
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

typedef long long _;
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

constant maxn = 1E5+8;

_ n, m, a[maxn], p[maxn], s;

int main() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) {
        a[i] = read();
        p[i] = p[i-1]+a[i];
    }
    ++n;
    for(_ i = 1; i <= n-1; ++i) if(i <= m+1) {
        _ c = p[i], lf = m-i+1;
        c += (lf>>1)*(a[i]+a[i+1]);
        if(lf & 1) c += a[i+1];
        s = max(s, c);
    }
    printf("%lld\n", s);
    
    return 0;
}

