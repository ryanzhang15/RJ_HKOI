#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, a, b, c, t;
bool r[maxn];

int main() {
    
    scanf("%lld%lld%lld", &n, &a, &b);
    c = (a*(a+1))>>1;
    t = (n*(n+1))>>2;
    for(_ i = 1; i <= a; ++i) r[i] = true;
    for(_ i = a, j = n; i && c < t; --i, --j) if(t-c >= b) {
        c += b;
        r[i] = false;
        r[j] = true;
    } else {
        r[i] = false;
        r[i+t-c] = true;
        break;
    }
    for(_ i = 1; i <= n; ++i) if(r[i]) printf("%lld ", i);
    putchar(10);
    for(_ i = 1; i <= n; ++i) if(!r[i]) printf("%lld ", i);
    putchar(10);
    
    return 0;
}
