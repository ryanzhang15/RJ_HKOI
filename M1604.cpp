#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, q, d, x;
set<_> s[maxn];

void out(bool b);
int main() {
    
    scanf("%lld%lld%lld", &n, &m, &q);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &d);
        for(; d--; ) {
            scanf("%lld", &x);
            s[x].insert(i);
        }
    }
    for(; q--; ) {
        scanf("%lld%lld%lld", &d, &x, &m);
        if(s[m].empty()) out(false);
        else {
            if(x >= d) out(s[m].lower_bound(d) != s[m].upper_bound(x));
            else out(s[m].lower_bound(d) != s[m].upper_bound(n) || s[m].lower_bound(1) != s[m].upper_bound(x));
        }
    }
    
    return 0;
}

void out(bool b) {
    if(b) puts("Yes");
    else puts("No");
}
