#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;
_ n, a[maxn], s = 9E18, p, c, cp, h, v;

int main() {
    
    scanf("%lld", &h);
    n = (h<<1)-1;
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) {
        if(i <= h) v = a[i]-i+1;
        else v = a[i]-(n-i)+1;
        c = 0;
        for(_ j = 1; j <= n; ++j) {
            if(a[j] != v) ++c;
            if(j == h) cp = v;
            if(j < h) ++v;
            else --v;
        }
        if(c < s || (c == s && cp > p)) {
            s = c;
            p = cp;
        }
    }
    
    printf("%lld\n%lld\n", s, p);
    
    return 0;
}
