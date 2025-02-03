#include <bits/stdc++.h>

const long long maxn = 1E6+8;
const long long maxq = 1E4+8;

long long n, m, q[maxq], l[maxn], c[maxn], t;
char a[maxn];

int main() {
    scanf("%lld %s%lld", &n, a+1, &m);
    for(int i = 1; i <= m; ++i) scanf("%lld", &q[i]);
    for(int i = 1; i <= n; ++i) if(a[i] == '<') ++t;
    for(int i = 2; i <= t; ++i) l[i] = l[i-1] + (a[i-1] == '>');
    for(int i = 1; i <= t; ++i) c[i] = (l[i]<<1) + (a[i] == '>');
    for(int i = n-1; i >= t + 1; --i) l[i] = l[i+1] + (a[i+1] == '<');
    for(int i = t+1; i <= n; ++i) c[i] = (l[i]<<1) + (a[i] == '<');
    for(int i = 1; i <= m; ++i) printf("%c\n", q[i] > t ? '>' : '<');
    for(int i = 1; i <= m; ++i) printf("%lld\n", c[q[i]]);
    return 0;
}
