#include <cstdio>
#include <iostream>
#include <stack>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, a[maxn], x;
stack<_> s;

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &x);
        _ c;
        for(c = 0; !s.empty() && x > s.top(); s.pop()) c = max(c, a[s.top()]);
        if(!s.empty()) a[x] = c+1;
        s.push(x);
    }
    
    for(_ i = 1; i <= n; ++i) printf("%lld ", a[i]);
    putchar(10);
    
    return 0;
}
