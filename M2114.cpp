
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef pair<_, _> _p;
typedef const long long constant;

inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline void AC();
int main() {
    
//#define MULTIPLE_TESTCASES
#ifdef MULTIPLE_TESTCASES
    _ tc = read();
    for(; tc--; ) AC();
#else
    AC();
#endif
    
    return 0;
}



// ------ separation line ------



constant maxn = 2E5+8;

_ n, a[maxn], l, r = 1E9, md, s, o;

bool check();
inline void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    sort(a+1, a+1+n);
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(check()) {
            s = md;
            r = md-1;
        } else l = md+1;
    }
    for(_ i = 1; i <= n; ++i, ++s) o += s-a[i];
    printf("%lld\n", o);
    
    return;
}

bool check() {
    _ c = md;
    for(_ i = 1; i <= n; ++i, ++c) if(a[i] > c) return false;
    return true;
}
