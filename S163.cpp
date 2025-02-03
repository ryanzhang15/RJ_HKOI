#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E4+8;

_ n, r, a[maxn], b[maxn];

void dfs(_ l, _ r);
int main() {
    
    scanf("%lld%lld", &r, &n);
    for(_ i = 1; i <= n; ++i) a[i] = i;
    dfs(1, n);
    for(_ i = 1; i <= n; ++i) {
        printf("%lld", a[i]);
        if(i < n) putchar(32);
    }
    
    
    return 0;
}

void dfs(_ l, _ r) {
    if(r-l+1 <= 2) return;
    _ cnt = 0;
    for(_ i = l; i <= r; ++++i) b[++cnt] = a[i];
    for(_ i = l+1; i <= r; ++++i) b[++cnt] = a[i];
    for(_ i = l; i <= r; ++i) a[i] = b[i-l+1];
    _ mid = (l+r)>>1;
    dfs(l, mid);
    dfs(mid+1, r);
    return ;
}
