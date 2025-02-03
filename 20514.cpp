#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;
_ n, m, a[maxn], ptr;
stack<_> s;

int main() {
    
    scanf("%lld%lld", &n, &m);
    
    for(; m--; ) {
        for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        ptr = 1;
        for(_ i = 1; i <= n; ++i) {
            s.push(i);
            for(; !s.empty() && s.top() == a[ptr]; s.pop()) ++ptr;
        }
        puts(ptr == n+1 ? "Yes" : "No");
        for(; !s.empty(); ) s.pop();
    }
    
    return 0;
}
