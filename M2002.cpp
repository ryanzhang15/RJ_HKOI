#include <cstdio>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;

_ n, m, q, x;
pair<_, bitset<101> > a[maxn];

bool cmp(pair<_, bitset<101> > a, pair<_, bitset<101> > b);
inline void write(_ x);
inline _ read();
int main() {
    
    n = read();
    m = read();
    q = read();
    for(register _ i = 1; i <= n; ++i) a[i].first = read();
    for(register _ i = 1; i <= n; ++i) for(register _ j = 1; j <= m; ++j) {
        x = read();
        if(x) a[i].second.set(j);
    }
    sort(a+1, a+1+n, cmp);
    for(; q--; ) {
        bitset<101> c;
        m = read();
        for(register _ i = 1; i <= m; ++i) {
            x = read();
            c.set(x);
        }
        bool ok = false;
        for(register _ i = 1; i <= n && !ok; ++i) if((c & a[i].second) == c) {
            write(a[i].first);
            putchar_unlocked(10);
            ok = true;
        }
        if(!ok) {
            putchar_unlocked('-');
            putchar_unlocked('1');
            putchar_unlocked(10);
        }
    }
    
    
    
    return 0;
}

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

bool cmp(pair<_, bitset<101> > a, pair<_, bitset<101> > b) {
    return a.first < b.first;
}
