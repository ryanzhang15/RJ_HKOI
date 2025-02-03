#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E5+8;
_ n, m, a[maxn], s, p = 1;
struct node {
    _ v, t;
};
deque<node> mx, mn;

inline _ read();
int main() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= n; ++i) {
        for(; !mx.empty() && mx.front().t < i; ) mx.pop_front();
        for(; !mn.empty() && mn.front().t < i; ) mn.pop_front();
        for(; p <= n; ++p) {
            for(; !mx.empty() && mx.back().v <= a[p]; ) mx.pop_back();
            for(; !mn.empty() && mn.back().v >= a[p]; ) mn.pop_back();
            mx.push_back((node){a[p], p});
            mn.push_back((node){a[p], p});
            if(mx.front().v - mn.front().v > m) break;
        }
        s += p-i;
    }
    
    printf("%lld\n", s);
    
    return 0;
}

inline _ read() {
    register _ x = 0, f = 1; register char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar_unlocked()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}
