
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, a[maxn], b[maxn], c[maxn], d[maxn], s;

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i]);
        s += (((c[i]-a[i])*(d[i]-b[i]))<<1) - a[i] - b[i] + c[i] + d[i];
        for(_ j = 1; j <= i-1; ++j) {
            if(a[i] == c[j] || c[i] == a[j]) s -= max((_)0, d[i]-b[i]+d[j]-b[j] - (max(d[i], d[j]) - min(b[i], b[j])));
            if(b[i] == d[j] || d[i] == b[j]) s -= max((_)0, c[i]-a[i]+c[j]-a[j] - (max(c[i], c[j]) - min(a[i], a[j])));
        }
    }
    
    printf("%lld\n", s);
    
    return 0;
}
