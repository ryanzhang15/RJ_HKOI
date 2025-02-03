
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>
#include <random>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}

inline void write(_ x) {
    if(x > 9) write(x/10);
    putchar_unlocked((x%10)^48);
    return;
}

str fileN = "";

// ----- End of Template -----

constant maxn = 2E5+8;

_ n, m, t[maxn], c[maxn], a[maxn], s;
priority_queue<_p, vector<_p>, greater<_p> > q;

int main(int argc, char * argv[]) {
    
//#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld", &t[i]);
        q.push(make_pair(t[i], i));
    }
    for(_ i = 1; i <= m; ++i) scanf("%lld", &c[i]);
    for(_ i = 1; i <= n; ++i) {
        _p x = q.top();
        q.pop();
        s += x.first;
        ++a[x.second];
        q.push(make_pair(t[x.second]+(c[x.second]*a[x.second]<<1), x.second));
    }
    printf("%lld\n", s);
    
    return 0;
}

